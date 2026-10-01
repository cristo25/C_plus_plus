#include "servicios/Biblioteca.h"
#include "../../../03_EDD/10_Busqueda/Busquedas.h"
// Usamos sort para ordenar o cambiar el orden de los datos.
#include <algorithm>
// Consultamos con numeric_limits el mayor entero permitido antes de sumar.
#include <limits>
// Avisamos de errores con mensajes, por ejemplo invalid_argument para un dato inválido.
#include <stdexcept>
// Usamos swap para intercambiar dos catálogos después de guardar.
#include <utility>

namespace proyecto {
    using namespace std;

    Biblioteca::Biblioteca(AlmacenCatalogo& almacen) : almacen(almacen), dao(almacen.cargar()) {
        for (const Libro& libro : dao.todos()) {
            validarTitulo(libro.titulo);
        }
    }

    void Biblioteca::validarTitulo(const string& titulo) {
        bool tieneTexto = false;
        // Buscamos al menos un carácter que no sea un espacio.
        for (char caracter : titulo) {
            if (caracter != ' ') {
                tieneTexto = true;
            }
        }
        if (!tieneTexto || titulo.size() > 200) {
            throw invalid_argument("El titulo debe contener texto y ocupar como maximo 200 bytes");
        }
        for (unsigned char caracter : titulo) {
            if (caracter < 32 || caracter == 127) {
                throw invalid_argument("El titulo no puede contener caracteres de control");
            }
        }
    }

    vector<const Libro*> Biblioteca::catalogoOrdenado() const {
        vector<const Libro*> vista;
        for (const Libro& libro : dao.todos()) {
            vista.push_back(&libro);
        }
        // Ordenamos tarjetas de lectura, sin reordenar el vector propietario del DAO.
        sort(vista.begin(), vista.end(), [](const Libro* izquierdo, const Libro* derecho) {
            return izquierdo->id < derecho->id;
        });
        return vista;
    }

    const Libro* Biblioteca::buscar(int id) const {
        const auto vista = catalogoOrdenado();
        vector<int> ids;
        for (const Libro* libro : vista) {
            ids.push_back(libro->id);
        }
        // Reutilizamos la búsqueda del curso: necesita IDs ordenados. La vista dura esta consulta.
        const auto posicion = binaria(ids, id);
        if (!posicion) {
            return nullptr;
        }
        return vista[*posicion];
    }

    void Biblioteca::registrar(const string& mensaje) {
        if (eventos.size() >= static_cast<size_t>(numeric_limits<int>::max())) {
            throw overflow_error("El historial supera el rango de sus indices");
        }
        const int indice = static_cast<int>(eventos.size());
        eventos.push_back(mensaje);
        try {
            orden.agregar(indice);
        } catch (...) {
            eventos.pop_back();
            throw;
        }
    }

    void Biblioteca::confirmar(LibroDAO& candidato, const string& mensaje) {
        // Guardamos una copia para poder deshacer el cambio. Si guardar falla, seguimos con los
        // libros anteriores.
        deshacerCambios.push(dao);
        try {
            almacen.guardar(candidato);
        } catch (...) {
            deshacerCambios.pop();
            throw;
        }
        swap(dao, candidato);
        registrar(mensaje);
    }

    void Biblioteca::agregarLibro(const Libro& libro) {
        validarTitulo(libro.titulo);
        LibroDAO candidato = dao;
        if (!candidato.crear(libro)) {
            throw invalid_argument("ID no positivo, duplicado o limite de 10000 libros alcanzado");
        }
        confirmar(candidato, "Libro agregado: " + to_string(libro.id));
    }

    void Biblioteca::renombrarLibro(int id, const string& titulo) {
        validarTitulo(titulo);
        LibroDAO candidato = dao;
        if (!candidato.actualizar(id, titulo)) {
            throw invalid_argument("No existe ese ID de libro");
        }
        confirmar(candidato, "Titulo actualizado: " + to_string(id));
    }

    void Biblioteca::eliminarLibro(int id) {
        LibroDAO candidato = dao;
        if (!candidato.eliminar(id)) {
            throw invalid_argument("No existe ese ID de libro");
        }
        confirmar(candidato, "Libro eliminado: " + to_string(id));
    }

    bool Biblioteca::deshacer() {
        if (deshacerCambios.empty()) {
            return false;
        }
        LibroDAO anterior = deshacerCambios.top();
        almacen.guardar(anterior);
        swap(dao, anterior);
        deshacerCambios.pop();
        registrar("Ultimo cambio del catalogo deshecho");
        return true;
    }

    void Biblioteca::solicitarEntrega(int id, size_t origen, size_t destino) {
        const Libro* libro = buscar(id);
        if (libro == nullptr) {
            throw invalid_argument("No existe ese ID de libro");
        }
        if (!red.rutaMinima(origen, destino)) {
            throw invalid_argument("No hay ruta entre esos edificios");
        }
        // Copiamos el libro antes de cualquier modificación futura del catálogo. La solicitud es
        // una copia completa.
        pendientes.push(Entrega{*libro, origen, destino});
        registrar("Entrega solicitada para libro: " + to_string(id));
    }

    optional<EntregaResuelta> Biblioteca::procesarEntrega() {
        if (pendientes.empty()) {
            return nullopt;
        }
        const Entrega& entrega = pendientes.front();
        const auto ruta = red.rutaMinima(entrega.origen, entrega.destino);
        if (!ruta) {
            throw logic_error("El mapa ya no permite completar la solicitud");
        }
        EntregaResuelta resultado{entrega, *ruta};
        registrar("Entrega completada para libro: " + to_string(entrega.libro.id));
        pendientes.pop();
        return resultado;
    }

    vector<Entrega> Biblioteca::entregasPendientes() const {
        // Consultar pendientes no consume la cola original: recorremos una copia.
        auto instantanea = pendientes;
        vector<Entrega> resultado;
        while (!instantanea.empty()) {
            resultado.push_back(instantanea.front());
            instantanea.pop();
        }
        return resultado;
    }

    vector<string> Biblioteca::historial(bool ordenInverso) const {
        const auto ids = ordenInverso ? orden.inversos() : orden.valores();
        vector<string> resultado;
        for (int indice : ids) {
            resultado.push_back(eventos[static_cast<size_t>(indice)]);
        }
        return resultado;
    }

    const MapaCampus& Biblioteca::mapa() const {
        return red;
    }
}

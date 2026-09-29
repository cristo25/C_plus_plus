#ifndef PROYECTO_BIBLIOTECA_H
#define PROYECTO_BIBLIOTECA_H

// Guardamos un resultado que puede faltar: optional tiene un valor o está vacío.
#include <optional>
// Atendemos por llegada con queue o por importancia con priority_queue.
#include <queue>
// Guardamos una pila: con stack sale primero lo último que entró.
#include <stack>
// Guardamos y trabajamos con texto mediante string.
#include <string>
// Guardamos una colección que puede crecer con vector.
#include <vector>
#include "datos/AlmacenCatalogo.h"
#include "servicios/MapaCampus.h"
#include "../../../03_EDD/03_Listas_Ligadas/02_Doblemente_Ligada/ListaDoble.h"

namespace proyecto {
    using namespace std;
    using namespace curso;

    class Biblioteca {
        // El almacén debe vivir más que Biblioteca; los otros miembros son propiedad de esta clase.
        AlmacenCatalogo& almacen;
        LibroDAO dao;
        MapaCampus red;
        queue<Entrega> pendientes;
        stack<LibroDAO> deshacerCambios;
        // Guardamos números de posición en los nodos; siguen sirviendo mientras solo agreguemos
        // mensajes al final.
        vector<string> eventos;
        ListaDoble orden;

        void registrar(const string& mensaje);
        void confirmar(LibroDAO candidato, const string& mensaje);
        static void validarTitulo(const string& titulo);
    public:
        explicit Biblioteca(AlmacenCatalogo& almacen);
        vector<const Libro*> catalogoOrdenado() const;
        const Libro* buscar(int id) const;
        void agregarLibro(const Libro& libro);
        void renombrarLibro(int id, const string& titulo);
        void eliminarLibro(int id);
        bool deshacer();
        void solicitarEntrega(int id, size_t origen, size_t destino);
        optional<EntregaResuelta> procesarEntrega();
        vector<Entrega> entregasPendientes() const;
        vector<string> historial(bool ordenInverso = false) const;
        const MapaCampus& mapa() const;
    };
}

#endif

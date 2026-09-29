#ifndef PROYECTO_BIBLIOTECA_H
#define PROYECTO_BIBLIOTECA_H

#include <optional>
#include <queue>
#include <stack>
#include <string>
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
        // Los nodos guardan índices estables, no direcciones que el vector pueda invalidar.
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

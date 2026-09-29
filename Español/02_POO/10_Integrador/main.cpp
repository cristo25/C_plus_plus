// Integrador: una biblioteca con objetos
//
// Usa composición para encapsular un DAO y herencia con dos vistas para practicar polimorfismo.
// Reutiliza el header del tema anterior. unique_ptr administra la vista y el destructor virtual
// permite liberar su tipo concreto.
//
// Analogía: La biblioteca tiene un bibliotecario y puede mostrar el catálogo en dos ventanillas:
// una detallada y otra resumida.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Agrega una vista que muestre solo los títulos y reutiliza el mismo DAO.
// La creación y la carga respetan el mismo límite de 10 000 libros.

#include "../09_DAO/LibroDAO.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;
using namespace curso;

class Biblioteca {
    // Composición: la biblioteca delega el almacenamiento al DAO.
    LibroDAO dao;

public:
    bool registrar(const Libro& libro) {
        return dao.crear(libro);
    }
    const LibroDAO& catalogo() const {
        return dao;
    }
};

class Vista {
public:
    virtual ~Vista() = default;
    virtual string mostrar(const LibroDAO& dao) const = 0;
};
class VistaDetalle : public Vista {
public:
    string mostrar(const LibroDAO& dao) const override {
        string texto;
        for (const auto& libro : dao.todos()) {
            texto += to_string(libro.id) + ": " + libro.titulo + "\n";
        }
        return texto;
    }
};
class VistaResumen : public Vista {
public:
    string mostrar(const LibroDAO& dao) const override {
        return "Libros: " + to_string(dao.todos().size()) + "\n";
    }
};

int main() {
    Biblioteca biblioteca;
    if (!(biblioteca.registrar({1, "Aprender C++"}))) {
        return 1;
    }
    if (biblioteca.registrar({1, "Duplicado"})) {
        return 1;
    }
    // La misma interfaz muestra detalle o resumen gracias al polimorfismo; unique_ptr administra
    // su vida.
    unique_ptr<Vista> vista = make_unique<VistaDetalle>();

    cout << vista->mostrar(biblioteca.catalogo());
    vista = make_unique<VistaResumen>();

    cout << vista->mostrar(biblioteca.catalogo());
}

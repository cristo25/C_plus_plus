// Integrador: una biblioteca con objetos
//
// Vamos a construir una pequeña biblioteca con varias clases que colaboran. Biblioteca contiene un
// DAO para guardar libros. Una Vista decide cómo mostrarlos: VistaDetalle escribe sus datos y
// VistaResumen muestra cuántos hay. Pedimos mostrar el catálogo de la misma manera aunque cambiemos
// de vista. Así reunimos composición, datos protegidos, consultas const y polimorfismo. Con
// unique_ptr dejamos claro quién se encarga de liberar la vista cuando ya no la usamos.
//

#include "../09_DAO/LibroDAO.h"
#include <iostream>
// Usamos unique_ptr para liberar automáticamente el objeto que administra.
#include <memory>
// Guardamos y trabajamos con texto mediante string.
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

#include "../09_DAO/LibroDAO.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;
using namespace curso;

class Biblioteca {
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
    unique_ptr<Vista> vista = make_unique<VistaDetalle>();

    cout << vista->mostrar(biblioteca.catalogo());
    vista = make_unique<VistaResumen>();

    cout << vista->mostrar(biblioteca.catalogo());
}

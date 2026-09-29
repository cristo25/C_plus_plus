#include "../LibroDAO.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    LibroDAO dao;
    if (!(dao.crear({1, "C++ inicial"}))) {
        return 1;
    }
    if (dao.crear({1, "Duplicado"})) {
        return 1;
    }
    if (dao.crear({0, "Invalido"})) {
        return 1;
    }
    if (!(dao.actualizar(1, "C++ paso a paso"))) {
        return 1;
    }
    const Libro* libro = dao.buscar(1);

    cout << libro->titulo << "\n";
    if (!(dao.eliminar(1))) {
        return 1;
    }
    if (!(!dao.buscar(1) && !dao.eliminar(1))) {
        return 1;
    }
}

#include "LibroDAO.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;
using namespace curso;

int main() {
    LibroDAO original;
    if (!(original.crear({1, "Estructuras"}))) {
        return 1;
    }
    if (!(original.crear({2, "Objetos"}))) {
        return 1;
    }
    if (!(original.actualizar(2, "Objetos y \"clases\""))) {
        return 1;
    }
    if (!(original.eliminar(1))) {
        return 1;
    }
    stringstream archivo;
    if (!(original.guardar(archivo))) {
        return 1;
    }
    LibroDAO copia;
    if (!(copia.cargar(archivo))) {
        return 1;
    }
    assert(copia.todos().size() == 1);
    assert(copia.buscar(2)->titulo == "Objetos y \"clases\"");
    istringstream duplicados("2\n2 \"Uno\"\n2 \"Dos\"\n");
    if (copia.cargar(duplicados)) {
        return 1;
    }
    assert(copia.todos().size() == 1);
    cout << copia.buscar(2)->titulo << "\n";
}

#include "Arbol.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    Arbol arbol;
    assert(arbol.valores().empty());
    for (int dato : {5, 3, 7, 2, 4, 6, 8}) {
        if (!(arbol.insertar(dato))) {
            return 1;
        }
    }
    assert(arbol.contiene(4));
    for (Recorrido orden : {Recorrido::Preorden, Recorrido::Inorden, Recorrido::Postorden}) {
        for (int dato : arbol.valores(orden)) {
            cout << dato << ' ';
        }
        cout << "\n";
    }
    if (!(arbol.eliminar(5))) {
        return 1;
    }
    assert((arbol.valores() == vector<int>{2, 3, 4, 6, 7, 8}));
    for (int dato : {2, 3, 4, 6, 7, 8}) {
        if (!(arbol.eliminar(dato))) {
            return 1;
        }
    }
    assert(arbol.valores().empty());
}

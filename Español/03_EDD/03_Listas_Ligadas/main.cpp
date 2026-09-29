#include "01_Simplemente_Ligada/ListaSimple.h"
#include "02_Doblemente_Ligada/ListaDoble.h"
#include "03_Circular/ListaCircular.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    ListaSimple simple;
    ListaDoble doble;
    ListaCircular circular;
    for (int dato : {10, 20, 30}) {
        simple.agregar(dato);
        doble.agregar(dato);
        circular.agregar(dato);
    }
    if (!(simple.eliminar(20) && doble.eliminar(20) && circular.eliminar(20))) {
        return 1;
    }
    const vector<int> esperado{10, 30};
    assert(simple.valores() == esperado && doble.valores() == esperado);
    assert(circular.valores() == esperado);
    assert((doble.inversos() == vector<int>{30, 10}));
    cout << "Simple: ";
    for (int dato : simple.valores()) {
        cout << dato << ' ';
    }
    cout << "\nDoble inversa: ";
    for (int dato : doble.inversos()) {
        cout << dato << ' ';
    }
    cout << "\nCircular (una vuelta): ";
    for (int dato : circular.valores()) {
        cout << dato << ' ';
    }
    cout << "\n";
}

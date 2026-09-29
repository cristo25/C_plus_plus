#include "ListaSimple.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    ListaSimple lista;
    if (!(lista.valores().empty() && !lista.eliminar(99))) {
        return 1;
    }
    lista.agregar(10);
    lista.agregar(20);
    lista.agregar(30);
    if (!(lista.eliminar(20))) {
        return 1;
    }

    for (int dato : lista.valores()) {
        cout << dato << ' ';
    }
    cout << "\n";
    if (!(lista.eliminar(10) && lista.eliminar(30))) {
        return 1;
    }
}

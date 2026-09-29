#include "../Arbol.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    Arbol arbol;
    for (int dato : {4, 2, 6, 1, 3, 5, 7}) {
        arbol.insertar(dato);
    }

    for (Recorrido orden : {Recorrido::Preorden, Recorrido::Inorden, Recorrido::Postorden}) {
        for (int dato : arbol.valores(orden)) {
            cout << dato << ' ';
        }
        cout << "\n";
    }
}

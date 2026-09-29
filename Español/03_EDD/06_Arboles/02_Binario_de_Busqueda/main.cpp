#include "../Arbol.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    Arbol arbol;
    if (!(!arbol.contiene(8) && !arbol.eliminar(8))) {
        return 1;
    }
    for (int dato : {8, 3, 10, 1, 6}) {
        if (!(arbol.insertar(dato))) {
            return 1;
        }
    }
    if (arbol.insertar(8)) {
        return 1;
    }

    if (!(arbol.eliminar(8))) {
        return 1; // Raiz con dos hijos.
    }

    for (int dato : arbol.valores()) {
        cout << dato << ' ';
    }
    cout << "\n";
    if (!(arbol.eliminar(1) && arbol.eliminar(3))) {
        return 1; // Hoja, luego un hijo.
    }
}

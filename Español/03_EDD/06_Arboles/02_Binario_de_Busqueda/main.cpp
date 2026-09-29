// Árbol binario de búsqueda (ABB)
//
// En este ABB los menores van a la izquierda y los mayores a la derecha; rechazamos duplicados.
// Para insertar, buscar o eliminar seguimos un camino entre niveles del árbol. El trabajo depende
// de cuántos niveles tenga ese camino: llamamos h a la altura, es decir, la cantidad de niveles del
// camino más largo (O(h)). Un árbol muy alargado puede obligarnos a pasar por casi todos sus nodos.
// Al borrar un nodo con dos hijos, lo sustituimos por el menor del subárbol derecho. Un ABB sin
// balancear puede degenerar en una cadena.
//
// Analogía: Una guía de números: cada nodo indica si seguir hacia los menores o hacia los
// mayores.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Inserta números ya ordenados y dibuja el árbol. Compara su altura con otro orden de
// inserción.

#include "../Arbol.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    Arbol arbol;
    // Al borrar una raíz con dos hijos, el header busca el sucesor y conserva la regla del ABB.
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

// Árboles
//
// Vamos a integrar las operaciones del árbol: insertar, buscar, recorrer y eliminar. Usamos Arbol.h
// para seguir los mismos enlaces en cada caso. Primero comprobamos el árbol vacío, agregamos datos,
// comparamos sus recorridos y al final retiramos todos los nodos. Podemos pensar en cuidar un árbol
// de carpetas: cada cambio debe conservar el acceso a las ramas que todavía existen.
//
// Práctica: Vamos a administrar números en un árbol.
// - Agreguemos números sin repetirlos y mostremos sus tres recorridos.
// - Eliminemos la raíz y comprobemos que los otros números sigan disponibles.

#include "Arbol.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    Arbol arbol;
    if (!(arbol.valores().empty())) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    for (int dato : {5, 3, 7, 2, 4, 6, 8}) {
        if (!(arbol.insertar(dato))) {
            return 1;
        }
    }
    if (!(arbol.contiene(4))) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    // El árbol es el mismo; cambiamos cuándo se visita la raíz respecto de sus dos ramas.
    for (Recorrido orden : {Recorrido::Preorden, Recorrido::Inorden, Recorrido::Postorden}) {
        for (int dato : arbol.valores(orden)) {
            cout << dato << ' ';
        }
        cout << "\n";
    }
    if (!(arbol.eliminar(5))) {
        return 1;
    }
    if (!((arbol.valores() == vector<int>{2, 3, 4, 6, 7, 8}))) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    for (int dato : {2, 3, 4, 6, 7, 8}) {
        if (!(arbol.eliminar(dato))) {
            return 1;
        }
    }
    if (!(arbol.valores().empty())) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
}

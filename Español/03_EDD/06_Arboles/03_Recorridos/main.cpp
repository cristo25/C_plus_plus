// Recorridos de un árbol
//
// Vamos a visitar el mismo árbol en tres órdenes. En preorden leemos primero el nodo y después
// sus ramas; en inorden leemos izquierda, nodo y derecha; en postorden dejamos el nodo para el
// final. En un árbol de búsqueda, inorden nos muestra los números ordenados. Podemos imaginar que
// recorremos las mismas habitaciones pero anotamos su nombre al entrar, a mitad de la visita o al
// salir. En todos los casos visitamos todos los nodos.
//
// Práctica: Vamos a recorrer el mismo árbol de tres formas.
// - Mostremos preorden, inorden y postorden.
// - Expliquemos en qué momento anotamos la raíz en cada recorrido.

#include "../Arbol.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    Arbol arbol;
    for (int dato : {4, 2, 6, 1, 3, 5, 7}) {
        arbol.insertar(dato);
    }

    // Preorden: raíz primero. Inorden: raíz entre ramas. Postorden: raíz al final.
    for (Recorrido orden : {Recorrido::Preorden, Recorrido::Inorden, Recorrido::Postorden}) {
        for (int dato : arbol.valores(orden)) {
            cout << dato << ' ';
        }
        cout << "\n";
    }
}

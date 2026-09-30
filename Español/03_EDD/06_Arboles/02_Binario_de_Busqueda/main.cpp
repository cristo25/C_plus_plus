// Árbol binario de búsqueda (ABB)
//
// Vamos a añadir una regla al árbol: los números menores van a la izquierda y los mayores a la
// derecha. Así, al buscar elegimos una rama y descartamos la otra. Llamamos a esta organización
// árbol binario de búsqueda, o ABB. Aquí no guardamos repetidos. Al borrar un nodo con dos hijos
// buscamos un reemplazo que conserve el orden. Si el árbol queda como una cadena, tendremos que
// recorrer muchos nodos; no basta con llamarlo árbol para que siempre busque rápido.
//
// Práctica: Vamos a guardar números ordenados por ramas.
// - Agreguemos valores menores y mayores que la raíz sin repetirlos.
// - Busquemos uno presente y otro ausente; después eliminemos uno.

#include "../Arbol.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    Arbol arbol;
    // Si quitamos la raíz con dos hijos, usamos el menor dato de la rama derecha como reemplazo
    // para conservar el orden.
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

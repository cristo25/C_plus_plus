// Burbuja
//
// Vamos a ordenar comparando vecinos. Si el de la izquierda es mayor, cambiamos sus posiciones;
// repetimos una pasada y el mayor pendiente acaba al final. Podemos imaginar burbujas grandes que
// van subiendo. Si una pasada no hace cambios, ya terminamos. Con n datos podemos repetir muchas
// comparaciones, aproximadamente como n por n (O(n²)); si ya estaban ordenados basta una pasada
// (O(n)). La función completa está en Ordenamientos.h.
//

#include "../Ordenamientos.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> datos{5, -1, 3, 3, 0};
    // La función intercambia vecinos invertidos y deja el mayor restante al final de cada
    // pasada.
    burbuja(datos);

    for (int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}

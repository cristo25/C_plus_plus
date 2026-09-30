// Burbuja
//
// Vamos a ordenar comparando vecinos. Si el de la izquierda es mayor, cambiamos sus posiciones;
// repetimos una pasada y el mayor pendiente acaba al final. Podemos imaginar burbujas grandes que
// van subiendo. Si una pasada no hace cambios, ya terminamos. Si los datos están al revés,
// hacemos muchas comparaciones; al duplicar la cantidad, estas pueden crecer hasta casi cuatro
// veces. Si ya están ordenados, basta una pasada. La función completa está en Ordenamientos.h.
//
// Práctica: Vamos a ordenar números como burbujas que suben.
// - Comparemos vecinos e intercambiémoslos cuando estén al revés.
// - Detengámonos si una pasada no cambia nada.

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

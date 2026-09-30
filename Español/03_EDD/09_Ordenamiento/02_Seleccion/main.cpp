// Selección
//
// Vamos a buscar el menor dato pendiente y colocarlo al principio de la zona sin ordenar. Después
// repetimos con el resto. Podemos imaginar que elegimos el libro más pequeño de un montón y lo
// ponemos en una fila. Aunque los números ya estén ordenados, seguimos buscando el menor de cada
// grupo. Con diez números hacemos muchas comparaciones; con veinte, cerca de cuatro veces más. Al
// intercambiar posiciones lejanas podemos cambiar el orden de elementos que empatan.
//
// Práctica: Vamos a ordenar eligiendo el menor pendiente.
// - Busquemos el menor valor en la parte sin ordenar.
// - Coloquémoslo al principio de esa parte y repitamos.

#include "../Ordenamientos.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> datos{5, -1, 3, 3, 0};
    // Busca el menor pendiente y lo coloca en la siguiente posición ordenada.
    seleccion(datos);

    for (int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}

// Selección
//
// Vamos a buscar el menor dato pendiente y colocarlo al principio de la zona sin ordenar. Después
// repetimos con el resto. Podemos imaginar que elegimos el libro más pequeño de un montón y lo
// ponemos en una fila. Aunque los números ya estén ordenados, seguimos buscando el menor de cada
// grupo; con n datos el trabajo crece aproximadamente como n por n (O(n²)). Al intercambiar
// posiciones lejanas podemos cambiar el orden de elementos que empatan.
//

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

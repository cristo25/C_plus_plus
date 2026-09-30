// Búsqueda lineal
//
// Vamos a buscar como si revisáramos un cajón casilla por casilla. No necesitamos ordenar antes:
// avanzamos hasta encontrar el dato o llegar al final. Podemos visitar todos los elementos. Para
// devolver el resultado usamos optional: una cajita de <optional> que puede guardar una posición
// o estar vacía. Comprobamos si contiene algo antes de leer *posicion. Una posición cero es un
// resultado válido; no debemos confundirla con «no encontrado».
//
// Práctica: Vamos a buscar un número casilla por casilla.
// - Probemos un número presente y otro ausente.
// - Mostremos la posición solo cuando lo encontremos.

#include "../Busquedas.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    const vector<int> datos{8, 3, 5, 3};
    auto posicion = lineal(datos, 3);

    // optional distingue no encontrado de índice cero; *posicion solo se usa si contiene un
    // índice.
    if (posicion) {
        cout << "Indice: " << *posicion << "\n";
    }
}

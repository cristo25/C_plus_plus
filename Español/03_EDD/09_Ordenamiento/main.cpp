// Algoritmos de ordenamiento
//
// Vamos a comprobar cinco maneras de ordenar usando las mismas entradas. Creamos una copia para
// cada algoritmo y comparamos su resultado con sort. Incluimos datos vacíos, negativos, repetidos y
// ya ordenados. Guardamos direcciones de funciones para poder llamar a cada algoritmo de la misma
// manera: igual que un puntero puede señalar una caja, un puntero a función puede señalar una tarea
// que podemos ejecutar. Si alguna comparación falla, mostramos el problema y terminamos.
//
// Práctica: Vamos a comparar maneras de ordenar números.
// - Probemos cada algoritmo con números repetidos y negativos.
// - Comprobemos que todos produzcan el mismo orden.

#include "Ordenamientos.h"
// Usamos sort para ordenar o cambiar el orden de los datos.
#include <algorithm>
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    // Un puntero a función permite probar los cinco algoritmos con la misma llamada.
    using Ordenar = void (*)(vector<int>&); // Direccion de una funcion.
    for (Ordenar ordenar : {burbuja, seleccion, insercion, mergeSort, quickSort}) {
        for (const vector<int>& entrada :
             vector<vector<int>>{{}, {1}, {4, 3, 2, 1}, {1, 2, 3, 4}, {2, 2, -1, 0, 2}}) {
            auto resultado = entrada;
            auto esperado = entrada;
            sort(esperado.begin(), esperado.end());
            ordenar(resultado);
            if (!(resultado == esperado)) {
                cerr << "La comprobacion no dio el resultado esperado.\n";
                return 1;
            }
        }
    }
    cout << "Los 5 algoritmos coinciden con sort en 5 entradas.\n";
}

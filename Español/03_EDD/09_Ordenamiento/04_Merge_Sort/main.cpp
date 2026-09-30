// Merge sort
//
// Vamos a dividir un montón en mitades hasta tener grupos pequeños y después reunirlos en orden.
// Podemos imaginar dos ayudantes que ordenan sus hojas: al juntarlas elegimos siempre la menor
// hoja disponible. Eso hace merge sort. Necesitamos otro espacio para la mezcla, que crece con la
// cantidad de datos. En cada nivel recorremos todos los datos y tenemos tantos niveles como
// divisiones por mitades. Ante un empate tomamos primero el dato de la izquierda para conservar
// su orden.
//
// Práctica: Vamos a ordenar dividiendo y reuniendo grupos.
// - Dividamos los datos hasta tener grupos pequeños.
// - Unamos las mitades en orden sin perder valores repetidos.

#include "../Ordenamientos.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> datos{5, -1, 3, 3, 0};
    // Divide por mitades y mezcla los grupos ordenados; el header muestra cada paso.
    mergeSort(datos);

    for (int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}

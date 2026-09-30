// Búsqueda
//
// Vamos a comparar la búsqueda uno por uno con la búsqueda por mitades. Primero buscamos en datos
// sin ordenar, después ordenamos y probamos ambas sobre el mismo vector. El número sigue siendo el
// mismo, pero su posición puede cambiar al ordenar. También contamos el trabajo previo: preparar
// una lista ordenada es una tarea adicional, aunque buscar dentro de ella después sea más rápido.
//
// Práctica: Vamos a comparar dos maneras de encontrar un número.
// - Busquemos en una lista sin ordenar revisando uno por uno.
// - Ordenemos otra lista y busquemos por mitades, comparando las posiciones.

#include "Busquedas.h"
// Usamos sort para ordenar o cambiar el orden de los datos.
#include <algorithm>
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> datos{8, 3, 5, 1, 3};
    if (!(lineal(datos, 8).value() == 0)) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    // La búsqueda binaria exige orden previo; ordenar cambia la posición original de los datos.
    sort(datos.begin(), datos.end());
    for (int buscado : {0, 1, 3, 5, 8, 99}) {
        if (!(lineal(datos, buscado) == binaria(datos, buscado))) {
            cerr << "La comprobacion no dio el resultado esperado.\n";
            return 1;
        }
    }
    cout << "Indice de 8 despues de ordenar: " << binaria(datos, 8).value() << "\n";
}

// Quick sort
//
// Vamos a elegir un dato como referencia para separar los demás; a ese dato lo llamamos pivote.
// Ponemos los menores de un lado y repetimos en cada grupo. Eso hace quick sort. Si los grupos
// quedan parejos, cada nivel revisa todos los datos y los niveles crecen por mitades. Aquí
// elegimos el último dato: con entradas ordenadas o iguales puede quedar casi todo de un lado y
// repetirse mucho trabajo. Esta elección nos ayuda a observar por qué importa el pivote.
//
// Práctica: Vamos a ordenar separando alrededor de un pivote.
// - Pongamos los menores a un lado del pivote.
// - Repitamos con cada parte y probemos una entrada ya ordenada.

#include "../Ordenamientos.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> datos{5, -1, 3, 3, 0};
    // El pivote separa valores menores; se repite el trabajo en las dos particiones.
    quickSort(datos);

    for (int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}

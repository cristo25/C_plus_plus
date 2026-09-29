// Quick sort
//
// Vamos a elegir un dato como referencia para separar los demás; a ese dato lo llamamos pivote.
// Ponemos los menores de un lado y repetimos en cada grupo. Eso hace quick sort. Si los grupos
// quedan parejos, cada nivel revisa los n datos y los niveles crecen por mitades (O(n log n)). Aquí
// elegimos el último dato: con entradas ordenadas o iguales puede quedar casi todo de un lado y
// repetirse mucho trabajo (O(n²), como n por n). Esta elección nos ayuda a observar por qué importa
// el pivote.
//

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

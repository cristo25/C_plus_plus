// Inserción
//
// Vamos a ordenar como una mano de cartas. Tomamos un dato nuevo y desplazamos los anteriores que
// sean mayores hasta abrirle un lugar. Así mantenemos ordenada la parte izquierda. Si los datos ya
// están ordenados avanzamos una sola vez (O(n), con n datos); si debemos desplazar muchos en cada
// paso, el trabajo puede crecer como n por n (O(n²)). Al no adelantar un dato sobre otro igual
// conservamos el orden de los empates.
//

#include "../Ordenamientos.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> datos{5, -1, 3, 3, 0};
    // Como ordenar cartas: abre un lugar en la zona izquierda para cada dato nuevo.
    insercion(datos);

    for (int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}

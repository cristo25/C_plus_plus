// Búsqueda binaria
//
// Vamos a buscar en una lista ya ordenada. Miramos el centro y decidimos en qué mitad podría estar
// el número. Podemos imaginar una guía de páginas numeradas: si buscamos una página menor,
// descartamos la mitad derecha. Reducir 16 candidatos a 8, 4, 2 y 1 requiere cuatro divisiones;
// empezar con 32 agrega solo otra (O(log n), donde n cuenta candidatos y log n describe las
// divisiones). Esta versión encuentra la primera coincidencia. Recibimos una posición o un
// resultado vacío y comprobamos cuál antes de leerlo.
//

#include "../Busquedas.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    // Los datos ya están ordenados: cada comparación puede descartar la mitad pendiente.
    const vector<int> datos{1, 3, 3, 5, 8};
    auto posicion = binaria(datos, 3);

    if (posicion) {
        cout << "Indice: " << *posicion << "\n";
    }
}

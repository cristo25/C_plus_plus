// Lista simplemente ligada
//
// Vamos a construir una cadena de cajas llamadas nodos. Cada nodo guarda un dato y un puntero al
// siguiente, como una nota que indica dónde está la próxima caja. La lista guarda la dirección del
// primero; el último señala nullptr. Para buscar seguimos las notas una a una: quizá debamos
// visitar los n nodos (O(n)). Al quitar un nodo unimos su vecino anterior con el siguiente antes de
// liberar la caja. Podemos ver esos pasos dentro de ListaSimple.h.
//

#include "ListaSimple.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    ListaSimple lista;
    if (!(lista.valores().empty() && !lista.eliminar(99))) {
        return 1;
    }
    // Los nodos formarán la cadena 10 -> 20 -> 30; los enlaces se implementan en el header.
    lista.agregar(10);
    lista.agregar(20);
    lista.agregar(30);
    if (!(lista.eliminar(20))) {
        return 1;
    }

    for (int dato : lista.valores()) {
        cout << dato << ' ';
    }
    cout << "\n";
    if (!(lista.eliminar(10) && lista.eliminar(30))) {
        return 1;
    }
}

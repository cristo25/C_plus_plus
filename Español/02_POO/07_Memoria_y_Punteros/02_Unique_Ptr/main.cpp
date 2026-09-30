// Propiedad con unique_ptr
//
// Vamos a dar a una sola herramienta la responsabilidad de liberar la caja. Con unique_ptr, de
// <memory>, guardamos esa responsabilidad junto con la dirección. make_unique crea el dato; get nos
// presta su dirección para consultarlo. Ese puntero prestado no debe liberarlo. Al terminar el
// programa, propietario libera el entero automáticamente. Esta ayuda evita que olvidemos un delete.
//

#include <iostream>
// Usamos unique_ptr para liberar automáticamente el objeto que administra.
#include <memory>

using namespace std;

int main() {
    auto propietario = make_unique<int>(42);
    // El observador accede al dato, pero no lo libera: no debe usar delete.
    int* observador = propietario.get();
    cout << *observador << "\n";
} // propietario libera el entero; observador deja de ser valido.

// Práctica: vamos a guardar una cantidad con unique_ptr.
// - Creamos el entero con make_unique y consultamos su dirección con get.
// - Mostramos el valor usando el puntero prestado.
// - Dejamos que unique_ptr libere el entero al terminar, sin llamar delete.

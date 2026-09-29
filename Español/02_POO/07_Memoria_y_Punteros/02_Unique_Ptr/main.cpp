// Propiedad con unique_ptr
//
// Vamos a dar a una sola herramienta la responsabilidad de liberar la caja. Con unique_ptr, de
// <memory>, guardamos esa responsabilidad junto con la dirección. make_unique crea el dato; get nos
// presta su dirección para consultarlo. Ese puntero prestado no debe liberarlo. Con move, de
// <utility>, trasladamos la responsabilidad a nuevoPropietario y dejamos vacío al anterior. Al
// terminar el nuevo propietario se libera el entero automáticamente. Esta ayuda evita que olvidemos
// un delete.
//

#include <iostream>
// Usamos unique_ptr para liberar automáticamente el objeto que administra.
#include <memory>
// Usamos move para trasladar los datos o la responsabilidad de liberarlos.
#include <utility>

using namespace std;

int main() {
    auto propietario = make_unique<int>(42);
    // El observador accede al dato, pero no lo libera: no debe usar delete.
    int* observador = propietario.get();
    // move transfiere la propiedad; el dueño anterior queda vacío y el dato sigue vivo.
    auto nuevoPropietario = move(propietario);

    cout << *observador << "\n";
} // nuevoPropietario libera el entero; observador deja de ser valido.

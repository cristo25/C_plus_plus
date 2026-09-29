// 3. Un arreglo de tarjetas para enteros
//
// Vamos a guardar direcciones en lugar de enteros. En int* direcciones[3] tenemos tres tarjetas:
// cada una puede señalar una caja que está fuera del arreglo. Con *direcciones[0] seguimos la
// primera tarjeta y cambiamos rojo; con direcciones[0] = &azul cambiamos únicamente la tarjeta.
// Podemos tener dos tarjetas para la misma caja, o nullptr cuando no elegimos ninguna. El arreglo
// guarda los punteros, pero no se encarga de borrar los enteros locales a los que apuntan.
//

#include <iostream>

using namespace std;

int main() {
    int rojo = 2;
    int azul = 5;
    int* direcciones[3]{&rojo, &azul, nullptr};

    // * cambia el entero de destino. rojo pasa de 2 a 7.
    *direcciones[0] = 7;
    // Sin * cambiamos la tarjeta. rojo sigue valiendo 7.
    direcciones[0] = &azul;
    for (const int* direccion : direcciones) {
        if (direccion != nullptr) {
            cout << *direccion << "\n";
        } else {
            cout << "Sin destino\n";
        }
    }
    cout << "Rojo conserva: " << rojo << "\n";
}

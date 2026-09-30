// Insertar y eliminar en vectores
//
// Vamos a abrir y quitar espacios en medio de un vector. Con begin() obtenemos una posición que
// señala el inicio; begin() + 1 señala el segundo elemento. A esa forma de señalar una posición
// la llamamos iterador. insert coloca un dato y desplaza los siguientes; erase quita uno y cierra
// el hueco. Por eso puede tocar mover casi todos los elementos. Después del cambio volvemos a
// obtener las posiciones que necesitamos. Antes de pop_back comprobamos empty para no quitar algo
// de un vector vacío.
//
// Práctica: Vamos a organizar una lista de números.
// - Insertemos un número en medio y quitemos otro.
// - Comprobemos que haya datos antes de quitar el último.

#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;

int main() {
    vector<int> numeros{10, 30};
    // begin() + 1 es la posición del segundo elemento: queda 10, 20, 30.
    numeros.insert(numeros.begin() + 1, 20);

    // Al borrar cerramos el hueco moviendo los siguientes datos. Después obtenemos de nuevo las
    // posiciones que necesitemos.
    numeros.erase(numeros.begin());

    if (!numeros.empty()) {
        numeros.pop_back();
    }

    cout << numeros.at(0) << "\n";
}

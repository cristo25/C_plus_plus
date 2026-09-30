// Una pila con vector
//
// Vamos a usar un vector como una pila de platos: solo ponemos y quitamos por arriba. Con push_back
// agregamos, con back miramos el último dato y con pop_back lo retiramos. El último en entrar es el
// primero en salir. Antes de consultar o quitar revisamos que la pila no esté vacía. Si necesitamos
// el dato retirado, lo guardamos antes de llamar pop_back, porque esa operación no lo devuelve.
//
// Práctica: Vamos a crear un historial sencillo con vector.
// - Agreguemos tres acciones al final.
// - Mostremos y quitemos la última solo si hay acciones.

#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;

int main() {
    vector<int> pila;

    pila.push_back(10);
    pila.push_back(20);
    // Antes de consultar back o eliminar, comprobamos que exista una cima.
    if (!pila.empty()) {
        const int cima = pila.back();
        pila.pop_back();

        cout << "Sale: " << cima << "\n";
    }
}

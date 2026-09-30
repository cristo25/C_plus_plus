// Cola FIFO
//
// Vamos a atender una fila por orden de llegada. Con queue, de <queue>, agregamos al final mediante
// push, consultamos al primero con front y lo retiramos con pop. Podemos imaginar una fila de
// personas esperando una ventanilla. Antes de atender revisamos empty. A la regla «primero en
// entrar, primero en salir» también la llamamos FIFO; las siglas solo abrevian esa misma idea.
//
// Práctica: Vamos a simular una fila de personas.
// - Agreguemos tres nombres en orden de llegada.
// - Atendamos uno por uno sin consultar una fila vacía.

#include <iostream>
// Atendemos por llegada con queue o por importancia con priority_queue.
#include <queue>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

int main() {
    queue<string> fila;
    fila.push("Ana");
    fila.push("Luis");

    // La persona al frente llegó primero; consultar y retirar requieren una cola no vacía.
    while (!fila.empty()) {
        cout << "Atender: " << fila.front() << "\n";
        fila.pop();
    }
}

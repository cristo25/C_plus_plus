// Colas
//
// Vamos a poner los mismos datos en una fila normal y en una fila con prioridad. Al guardar 2, 9 y
// 4, la primera conserva ese orden; la segunda atiende primero el 9. Así podemos decidir qué regla
// necesita una aplicación: respetar la llegada o elegir por importancia. Cambiar la estructura
// cambia esa regla de atención, aunque los datos sean iguales.
//

#include <iostream>
// Atendemos por llegada con queue o por importancia con priority_queue.
#include <queue>

using namespace std;

int main() {
    queue<int> llegada;
    priority_queue<int> prioridad;
    for (int dato : {2, 9, 4}) {
        llegada.push(dato);
        prioridad.push(dato);
    }
    cout << "FIFO: ";
    // FIFO conserva la llegada; la cola de prioridad elegirá después el mayor valor disponible.
    while (!llegada.empty()) {
        cout << llegada.front() << ' ';
        llegada.pop();
    }
    cout << "\nPrioridad: ";
    while (!prioridad.empty()) {
        cout << prioridad.top() << ' ';
        prioridad.pop();
    }
    cout << "\n";
}

// Colas
//
// Compara orden de llegada y orden de prioridad. El integrador produce 2 9 4 con FIFO y 9 4 2
// con prioridad.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe

#include <iostream>
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

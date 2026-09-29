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

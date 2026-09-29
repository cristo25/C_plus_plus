#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<int> gravedad;
    priority_queue<int, vector<int>, greater<int>> costo;
    for (int dato : {2, 9, 4}) {
        gravedad.push(dato);
        costo.push(dato);
    }

    cout << "Mayor prioridad: " << gravedad.top() << "\n";
    cout << "Menor costo: " << costo.top() << "\n";
}

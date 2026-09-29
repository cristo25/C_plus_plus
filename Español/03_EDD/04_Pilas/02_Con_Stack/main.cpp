#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<string> historial;
    historial.push("Escribir");
    historial.push("Borrar");
    if (!historial.empty()) {

        cout << "Deshacer: " << historial.top() << "\n";
        historial.pop();
    }
}

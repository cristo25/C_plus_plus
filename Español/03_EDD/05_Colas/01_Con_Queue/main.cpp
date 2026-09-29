#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<string> fila;
    fila.push("Ana");
    fila.push("Luis");

    while (!fila.empty()) {
        cout << "Atender: " << fila.front() << "\n";
        fila.pop();
    }
}

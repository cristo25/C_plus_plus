#include <iostream>

using namespace std;

int main() {
    int* numero = new int(42);

    cout << *numero << "\n";
    delete numero;
    numero = nullptr; // Evita reutilizar esta direccion por accidente.
}

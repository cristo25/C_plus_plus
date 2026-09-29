#include <iostream>
#include <memory>
#include <utility>

using namespace std;

int main() {
    auto propietario = make_unique<int>(42);
    int* observador = propietario.get();
    auto nuevoPropietario = move(propietario);

    cout << *observador << "\n";
} // nuevoPropietario libera el entero; observador deja de ser valido.

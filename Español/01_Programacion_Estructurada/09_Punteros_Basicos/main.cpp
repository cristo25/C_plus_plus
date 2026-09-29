#include <iostream>

using namespace std;

int main() {
    int caja = 10;
    int* direccion = &caja; // No es propietario: caja administra su propia vida.
    *direccion = 25;

    int* sinDestino = nullptr;
    if (sinDestino != nullptr) {
        cout << *sinDestino << "\n";
    }
    cout << "Contenido: " << *direccion << "\n";
}

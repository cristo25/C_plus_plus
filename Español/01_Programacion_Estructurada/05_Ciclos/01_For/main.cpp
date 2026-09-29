#include <iostream>

using namespace std;

int sumaHasta(int limite) {
    int suma = 0;
    for (int numero = 1; numero <= limite; ++numero) {
        suma += numero;
    }
    return suma;
}

int main() {

    cout << sumaHasta(5) << "\n";
}

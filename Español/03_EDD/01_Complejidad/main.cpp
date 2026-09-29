#include <iostream>

using namespace std;

int pasosMitad(int n) {
    int pasos = 0;
    while (n > 1) {
        n /= 2;
        ++pasos;
    }
    return pasos;
}

int main() {
    cout << "Recorrido de 1024 elementos: 1024 visitas\n";
    cout << "Dividir 1024 hasta 1: " << pasosMitad(1024) << " pasos\n";
}

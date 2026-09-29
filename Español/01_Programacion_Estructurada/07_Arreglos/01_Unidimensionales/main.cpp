#include <array>
#include <iostream>

using namespace std;

int main() {
    array<int, 4> cajon{10, 20, 30, 40};
    int suma = 0;
    for (int valor : cajon) {
        suma += valor;
    }
    cajon.at(1) = 25;

    cout << "Suma original: " << suma << "\n";
}

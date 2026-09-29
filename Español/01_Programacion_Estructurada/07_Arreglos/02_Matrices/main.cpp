#include <array>
#include <iostream>

using namespace std;

int main() {
    array<array<int, 3>, 2> mueble{{{1, 2, 3}, {4, 5, 6}}};
    for (const auto& fila : mueble) {
        for (int valor : fila) {
            cout << valor << ' ';
        }
        cout << "\n";
    }
}

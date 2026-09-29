#include <array>
#include <iostream>

using namespace std;

int main() {
    array<array<int, 3>, 2> notas{{{8, 9, 10}, {7, 8, 9}}};
    array<double, 2> promedios{};
    for (size_t fila = 0; fila < notas.size(); ++fila) {
        int suma = 0;
        for (int nota : notas.at(fila)) {
            suma += nota;
        }
        promedios.at(fila) = static_cast<double>(suma) / notas.at(fila).size();
    }

    for (double promedio : promedios) {
        cout << promedio << "\n";
    }
}

#include "Calificaciones.h"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace curso;

int main() {
    const array<int, 3> notas{8, 9, 10};
    try {
        const double promedio = calcularPromedio(notas);
        cout << "Promedio: " << promedio << "\n";
        if (estaAprobado(promedio)) {
            cout << "Aprobado\n";
        } else {
            cout << "Reprobado\n";
        }
    } catch (const invalid_argument& error) {
        cerr << error.what() << "\n";
        return 1;
    }
}

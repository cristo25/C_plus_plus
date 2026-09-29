#include "Calificaciones.h"
#include <stdexcept>

using namespace std;

namespace curso {
    double calcularPromedio(const array<int, 3>& notas) {
        int suma = 0;
        // Cada nota se valida antes de sumarla; la referencia const no permite cambiar el
        // arreglo.
        for (const int nota : notas) {
            if (nota < NOTA_MINIMA || nota > NOTA_MAXIMA) {
                throw invalid_argument("Las notas deben estar entre 0 y 10");
            }
            suma += nota;
        }
        // La conversión antes de dividir evita truncar el promedio como un entero.
        return static_cast<double>(suma) / notas.size();
    }

    bool estaAprobado(double promedio) {
        return promedio >= NOTA_APROBATORIA;
    }
} // namespace curso

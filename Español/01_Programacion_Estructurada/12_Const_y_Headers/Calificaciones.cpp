#include "Calificaciones.h"

using namespace std;

namespace curso {
    bool calcularPromedio(const int notas[], int cantidad, double& resultado) {
        if (cantidad <= 0) {
            return false;
        }
        long long suma = 0;
        // Cada nota se valida antes de sumarla; const nos impide cambiar las notas desde esta función.
        for (int indice = 0; indice < cantidad; ++indice) {
            const int nota = notas[indice];
            if (nota < NOTA_MINIMA || nota > NOTA_MAXIMA) {
                return false;
            }
            suma += nota;
        }
        // Convertimos antes de dividir para conservar los decimales del promedio.
        resultado = static_cast<double>(suma) / cantidad;
        return true;
    }

    bool estaAprobado(double promedio) {
        return promedio >= NOTA_APROBATORIA;
    }
} // namespace curso

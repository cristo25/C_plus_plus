// Arreglos
//
// Vamos a combinar un arreglo de una dimensión con una matriz. En notas guardamos dos alumnos, cada
// uno con tres calificaciones; en promedios guardamos un resultado por alumno. Recorremos una fila,
// sumamos sus notas y dividimos entre tres. Con static_cast<double> tratamos la suma como un número
// con decimales antes de dividir, para conservar la parte decimal del promedio.
//

#include <iostream>

using namespace std;

int main() {
    // Cada fila guarda las tres notas de un alumno; las posiciones empiezan en cero.
    int notas[2][3]{{8, 9, 10}, {7, 8, 9}};
    double promedios[2]{};
    for (size_t fila = 0; fila < 2; ++fila) {
        int suma = 0;
        for (int nota : notas[fila]) {
            suma += nota;
        }
        // Convertimos la suma a double para que el promedio no pierda su parte decimal.
        promedios[fila] = static_cast<double>(suma) / 3;
    }

    for (double promedio : promedios) {
        cout << promedio << "\n";
    }
}

// Arreglos
//
// Vamos a combinar un arreglo de una dimensión con una matriz. En notas guardamos dos alumnos, cada
// uno con tres calificaciones; en promedios guardamos un resultado por alumno. Recorremos una fila,
// sumamos sus notas y dividimos entre 3.0. Al escribir 3.0, la división conserva los decimales del
// promedio.
//

// Práctica: Vamos a realizar un programa integrador de calificaciones por alumno.
//
// - Guardar tres alumnos con cuatro notas cada uno en una matriz.
// - Guardar los tres promedios en otro arreglo.
// - Mostrar el promedio y si cada alumno aprobó.
// - Mantener las notas entre 0 y 10.

#include <iostream>

using namespace std;

int main() {
    // Cada fila guarda las tres notas de un alumno; las posiciones empiezan en cero.
    int notas[2][3]{{8, 9, 10}, {7, 8, 9}};
    double promedios[2]{};
    for (int fila = 0; fila < 2; ++fila) {
        int suma = 0;
        for (int nota : notas[fila]) {
            suma += nota;
        }
        // Con 3.0 obtenemos un resultado con decimales.
        promedios[fila] = suma / 3.0;
    }

    for (double promedio : promedios) {
        cout << promedio << "\n";
    }
}

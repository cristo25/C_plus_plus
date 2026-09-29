// Arreglos
//
// Empieza con un cajón y después con un mueble. El integrador guarda notas en una matriz y sus
// promedios en un arreglo: 9 y 8.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe

#include <array>
#include <iostream>

using namespace std;

int main() {
    // Cada fila guarda las tres notas de un alumno; las posiciones empiezan en cero.
    array<array<int, 3>, 2> notas{{{8, 9, 10}, {7, 8, 9}}};
    array<double, 2> promedios{};
    for (size_t fila = 0; fila < notas.size(); ++fila) {
        int suma = 0;
        for (int nota : notas.at(fila)) {
            suma += nota;
        }
        // Convertimos la suma a double para que el promedio no pierda su parte decimal.
        promedios.at(fila) = static_cast<double>(suma) / notas.at(fila).size();
    }

    for (double promedio : promedios) {
        cout << promedio << "\n";
    }
}

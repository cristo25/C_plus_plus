// Burbuja
//
// Compara vecinos y los intercambia si están invertidos. Cada pasada coloca el mayor restante al
// final. Tiempo O(n²) en promedio y peor caso; O(n) si ya está ordenado gracias al indicador de
// cambios. Memoria adicional O(1). Es estable. Lee su función en ../Ordenamientos.h.
//
// Analogía: Las burbujas grandes suben al extremo; cada pasada lleva el mayor número al final.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Dibuja cada pasada para los datos 4, 2, 3, 1.

#include "../Ordenamientos.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> datos{5, -1, 3, 3, 0};
    // La función intercambia vecinos invertidos y deja el mayor restante al final de cada
    // pasada.
    burbuja(datos);

    for (int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}

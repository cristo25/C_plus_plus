// Selección
//
// Busca el menor de la zona pendiente y lo intercambia con su primera posición. Tiempo O(n²),
// incluso si ya estaba ordenado; memoria adicional O(1). No es estable en esta implementación.
// Lee su función en ../Ordenamientos.h.
//
// Analogía: De un montón de cartas tomas siempre la menor y la colocas en la siguiente posición
// libre.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Cuenta comparaciones para cuatro valores y compáralas con burbuja.

#include "../Ordenamientos.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> datos{5, -1, 3, 3, 0};
    // Busca el menor pendiente y lo coloca en la siguiente posición ordenada.
    seleccion(datos);

    for (int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}

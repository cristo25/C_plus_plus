// Inserción
//
// Mantiene una zona izquierda ordenada e inserta cada dato nuevo desplazando los mayores. Tiempo
// O(n²) en promedio y peor caso, O(n) en datos ya ordenados; memoria adicional O(1). Es estable.
// Lee su función en ../Ordenamientos.h.
//
// Analogía: Ordenas una mano de cartas colocando cada carta nueva en su lugar entre las
// anteriores.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Traza los desplazamientos cuando insertas el 2 en 1, 3, 4.

#include "../Ordenamientos.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> datos{5, -1, 3, 3, 0};
    // Como ordenar cartas: abre un lugar en la zona izquierda para cada dato nuevo.
    insercion(datos);

    for (int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}

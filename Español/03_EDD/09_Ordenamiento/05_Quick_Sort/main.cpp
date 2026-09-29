// Quick sort
//
// Elige un pivote, coloca los menores a un lado y ordena las particiones. Suele costar O(n log
// n), pero esta elección de pivote llega a O(n²) con entradas ordenadas o iguales. La pila
// recursiva puede crecer hasta O(n). No es estable. Lee su función en ../Ordenamientos.h.
//
// Analogía: Un pivote divide una fila: los menores pasan a la izquierda y los demás a la
// derecha; repites en cada grupo.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Traza el pivote en 4, 1, 3, 2. Prueba datos ordenados y explica por qué esta versión
// se desequilibra.

#include "../Ordenamientos.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> datos{5, -1, 3, 3, 0};
    // El pivote separa valores menores; se repite el trabajo en las dos particiones.
    quickSort(datos);

    for (int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}

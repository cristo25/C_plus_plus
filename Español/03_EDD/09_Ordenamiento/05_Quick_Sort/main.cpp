// Quick sort
//
// Elige un pivote, coloca los menores a un lado y ordena las particiones. Cuando las particiones
// quedan repartidas de forma parecida, cada nivel procesa los n datos y la cantidad de niveles
// crece como las divisiones por mitades (O(n log n); n cuenta datos). Si el pivote deja casi todo
// en un solo lado, repetimos recorridos largos y el trabajo puede crecer como n multiplicado por n
// (O(n²)); elegir el último dato como pivote provoca ese caso con entradas ordenadas o iguales.
// También pueden acumularse hasta una llamada pendiente por dato (O(n) de memoria para las
// llamadas). No es estable. Lee su función en ../Ordenamientos.h.
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

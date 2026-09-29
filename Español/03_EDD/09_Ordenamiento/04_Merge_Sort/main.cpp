// Merge sort
//
// Divide por mitades, ordena cada mitad y las mezcla. Dividir por mitades crea varios niveles de
// trabajo; duplicar la cantidad de datos añade aproximadamente un nivel. En cada nivel, las mezclas
// recorren en conjunto los n datos: el trabajo combina la cantidad de datos con la cantidad de
// niveles (O(n log n); n cuenta datos y log n describe los niveles de división). Necesita un
// arreglo auxiliar que crece con esos datos (O(n) de memoria) y guarda las llamadas pendientes del
// camino de divisiones actual (O(log n) de memoria para las llamadas). Es estable porque, ante
// empates, toma primero el elemento de la izquierda. Lee su función en ../Ordenamientos.h.
//
// Analogía: Divides hojas entre dos ayudantes y luego reúnes sus montones ordenados tomando la
// menor hoja disponible.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Dibuja las divisiones y mezclas de seis números. Observa que el final del rango se
// excluye.

#include "../Ordenamientos.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> datos{5, -1, 3, 3, 0};
    // Divide por mitades y mezcla los grupos ordenados; el header muestra cada paso.
    mergeSort(datos);

    for (int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}

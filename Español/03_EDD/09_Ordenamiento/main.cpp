// Algoritmos de ordenamiento
//
// Estudia cada algoritmo con la misma entrada y compara trabajo, memoria y estabilidad. Estable
// significa conservar el orden original de elementos con la misma clave. El integrador verifica
// cinco algoritmos contra sort, incluyendo vector vacío, repetidos, negativos y datos ya
// ordenados. Los punteros a funciones permiten repetir la misma comprobación.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe

#include "Ordenamientos.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    // Un puntero a función permite probar los cinco algoritmos con la misma llamada.
    using Ordenar = void (*)(vector<int>&); // Direccion de una funcion.
    for (Ordenar ordenar : {burbuja, seleccion, insercion, mergeSort, quickSort}) {
        for (const vector<int>& entrada :
             vector<vector<int>>{{}, {1}, {4, 3, 2, 1}, {1, 2, 3, 4}, {2, 2, -1, 0, 2}}) {
            auto resultado = entrada;
            auto esperado = entrada;
            sort(esperado.begin(), esperado.end());
            ordenar(resultado);
            // assert comprueba un resultado del integrador; no realiza operaciones del programa.
            assert(resultado == esperado);
        }
    }
    cout << "Los 5 algoritmos coinciden con sort en 5 entradas.\n";
}

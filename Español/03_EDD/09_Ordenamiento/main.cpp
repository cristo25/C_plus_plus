#include "Ordenamientos.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    using Ordenar = void (*)(vector<int>&); // Direccion de una funcion.
    for (Ordenar ordenar : {burbuja, seleccion, insercion, mergeSort, quickSort}) {
        for (const vector<int>& entrada :
             vector<vector<int>>{{}, {1}, {4, 3, 2, 1}, {1, 2, 3, 4}, {2, 2, -1, 0, 2}}) {
            auto resultado = entrada;
            auto esperado = entrada;
            sort(esperado.begin(), esperado.end());
            ordenar(resultado);
            assert(resultado == esperado);
        }
    }
    cout << "Los 5 algoritmos coinciden con sort en 5 entradas.\n";
}

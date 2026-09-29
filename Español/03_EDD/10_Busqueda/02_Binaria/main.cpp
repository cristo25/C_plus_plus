// Búsqueda binaria
//
// Requiere un vector ordenado de menor a mayor. Cada comparación descarta la mitad del rango;
// tiempo O(log n), espacio auxiliar O(1). Ordenar primero tiene su propio costo: no es gratis.
// Esta versión devuelve la primera coincidencia.
//
// Analogía: Abres una guía ordenada por la mitad y decides qué mitad conserva el número que
// buscas.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Dibuja los rangos al buscar 8. Explica por qué no debes usarla directamente con 8,
// 1, 3.

#include "../Busquedas.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    // Los datos ya están ordenados: cada comparación puede descartar la mitad pendiente.
    const vector<int> datos{1, 3, 3, 5, 8};
    auto posicion = binaria(datos, 3);

    if (posicion) {
        cout << "Indice: " << *posicion << "\n";
    }
}

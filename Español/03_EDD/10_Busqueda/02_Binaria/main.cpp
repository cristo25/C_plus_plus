// Búsqueda binaria
//
// Requiere un vector ordenado de menor a mayor. Cada paso reduce la zona pendiente aproximadamente
// a la mitad. Imagina reducir 16 candidatos a 8, después a 4, a 2 y a 1: son cuatro divisiones. Si
// comenzamos con 32, solo agregamos una división a ese recorrido. Por eso el trabajo crece
// lentamente al aumentar los datos (O(log n), donde n es la cantidad de elementos y log n describe
// ese crecimiento por mitades). Esta versión usa unas pocas variables, sin copiar el vector (O(1)
// de memoria adicional). Ordenar primero tiene su propio costo: no es gratis. Esta versión devuelve
// la primera coincidencia.
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

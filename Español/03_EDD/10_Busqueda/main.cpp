// Búsqueda
//
// Busca primero sin orden y después con orden. El integrador compara resultados de ambas
// búsquedas sobre datos ordenados y muestra cómo cambia el índice original: el 8 pasa de 0 a 4.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe

#include "Busquedas.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> datos{8, 3, 5, 1, 3};
    // assert comprueba un resultado del integrador; no realiza operaciones del programa.
    assert(lineal(datos, 8).value() == 0);
    // La búsqueda binaria exige orden previo; ordenar cambia la posición original de los datos.
    sort(datos.begin(), datos.end());
    for (int buscado : {0, 1, 3, 5, 8, 99}) {
        assert(lineal(datos, buscado) == binaria(datos, buscado));
    }
    cout << "Indice de 8 despues de ordenar: " << binaria(datos, 8).value() << "\n";
}

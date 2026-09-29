// Búsqueda lineal
//
// Revisa desde el inicio hasta encontrar el valor. No necesita orden previo. Tiempo O(n);
// espacio auxiliar O(1). optional contiene una posición o nullopt si no existe. Comprueba que
// tiene valor antes de usar *resultado. La posición 0 también es un resultado válido.
//
// Analogía: Buscas una llave revisando cada compartimento del cajón.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Busca el primer elemento, el último y uno inexistente.

#include "../Busquedas.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    const vector<int> datos{8, 3, 5, 3};
    auto posicion = lineal(datos, 3);

    // optional distingue no encontrado de índice cero; *posicion solo se usa si contiene un
    // índice.
    if (posicion) {
        cout << "Indice: " << *posicion << "\n";
    }
}

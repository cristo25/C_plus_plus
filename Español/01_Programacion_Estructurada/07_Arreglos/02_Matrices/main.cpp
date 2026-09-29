// Matrices
//
// Una matriz tiene filas y columnas. Aquí usamos un array de arreglos; ambos índices comienzan
// en cero.
//
// Analogía: Un mueble tiene varios cajones (filas) y cada cajón tiene compartimentos (columnas).
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Calcula la suma de cada fila por separado.

#include <array>
#include <iostream>

using namespace std;

int main() {
    // Un mueble con dos cajones y tres secciones por cajón: dos filas y tres columnas.
    array<array<int, 3>, 2> mueble{{{1, 2, 3}, {4, 5, 6}}};
    // La referencia const recorre cada fila sin copiar sus elementos ni modificarla.
    for (const auto& fila : mueble) {
        for (int valor : fila) {
            cout << valor << ' ';
        }
        cout << "\n";
    }
}

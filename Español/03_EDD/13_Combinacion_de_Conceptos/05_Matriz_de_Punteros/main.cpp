// 5. Un arreglo de arreglos de punteros
//
// Una vitrina tiene filas; cada fila tiene casillas con tarjetas para productos.
// array<array<Producto*, 2>, 2> contiene dos filas de dos punteros. Dos tarjetas
// pueden señalar el mismo producto; una casilla nullptr está vacía. La matriz
// no es Producto**: contiene arreglos de tamaño fijo, no punteros a filas.
// El inventario es propietario; la vitrina solo muestra posiciones. Cambiar
// el objeto original se observa desde todas las tarjetas que apuntan a él.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../../02_POO/08_Headers/Producto.cpp -o programa.exe
// Ejecutar: ./programa.exe
//
// Practica: Cambia una casilla por nullptr. Explica por qué contar casillas no cuenta productos únicos.

#include <array>
#include <iostream>
#include "../../../02_POO/08_Headers/Producto.h"

using namespace std;
using namespace curso;

int main() {
    array<Producto, 2> productos{
        Producto("Cuaderno", 300),
        Producto("Lapiz", 100)
    };
    const array<array<Producto*, 2>, 2> casillas{
        array<Producto*, 2>{&productos.at(0), nullptr},
        array<Producto*, 2>{&productos.at(1), &productos.at(0)}
    };

    // const protege las tarjetas de la matriz, no sus destinos. Este destino conocido existe.
    *casillas.at(0).at(0) = Producto("Cuaderno grande", 400);
    for (const auto& fila : casillas) {
        for (const Producto* producto : fila) {
            if (producto != nullptr) {
                // producto->metodo() equivale a (*producto).metodo(). Consultamos por const Producto*.
                cout << producto->consultarNombre() << " | ";
            } else {
                cout << "Vacia | ";
            }
        }
        cout << "\n";
    }
}

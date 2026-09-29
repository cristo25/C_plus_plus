// 1. Un arreglo que contiene objetos
//
// Primero decidimos qué guardar: productos con nombre y precio. Reutilizamos
// Producto.h de POO. array<Producto, 3> contiene tres objetos, como un cajón
// con tres compartimentos ocupados por productos completos, no por direcciones.
// El arreglo administra la vida de esos objetos. const auto& permite consultarlos
// sin copiar cada producto ni modificarlo mediante esa referencia.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../../02_POO/08_Headers/Producto.cpp -o programa.exe
// Ejecutar: ./programa.exe
//
// Practica: Cambia un precio y predice el total. Explica por qué aquí no usamos punteros.

#include <array>
#include <iostream>
#include "../../../02_POO/08_Headers/Producto.h"

using namespace std;
using namespace curso;

int main() {
    const array<Producto, 3> productos{
        Producto("Cuaderno", 300),
        Producto("Lapiz", 100),
        Producto("Libro", 500)
    };

    long long valorTotal = 0;
    // Cada referencia es una etiqueta temporal de uno de los tres objetos del arreglo.
    for (const Producto& producto : productos) {
        cout << producto.consultarNombre() << ": " << producto.consultarPrecio() << "\n";
        valorTotal += producto.consultarPrecio();
    }
    cout << "Total en centavos: " << valorTotal << "\n";
}

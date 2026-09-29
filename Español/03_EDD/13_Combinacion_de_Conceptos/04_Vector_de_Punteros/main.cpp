// 4. Un vector de punteros: una vista del inventario
//
// El inventario es un array de objetos; la vista es un vector de sus direcciones.
// La vista puede crecer y repetir un producto sin copiarlo. Reasignar un puntero
// de la vista cambia la selección, no el inventario. Producto*& recibe una
// referencia a una tarjeta y Producto& una referencia al nuevo destino.
// Aunque el vector reubique sus tarjetas al crecer, los productos de este array
// local siguen en el mismo sitio. El inventario debe vivir más que la vista.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../../02_POO/08_Headers/Producto.cpp -o programa.exe
// Ejecutar: ./programa.exe
//
// Practica: Selecciona otro producto y explica qué elemento cambia y cuáles permanecen.

#include <array>
#include <iostream>
#include <vector>
#include "../../../02_POO/08_Headers/Producto.h"

using namespace std;
using namespace curso;

void seleccionar(Producto*& seleccion, Producto& nuevoDestino) {
    seleccion = &nuevoDestino;
}

int main() {
    array<Producto, 3> productos{
        Producto("Cuaderno", 300),
        Producto("Lapiz", 100),
        Producto("Libro", 500)
    };
    vector<Producto*> vista{&productos.at(0), &productos.at(1)};
    // at(0) devuelve una referencia al puntero guardado: int*& funciona igual.
    seleccionar(vista.at(0), productos.at(2));
    vista.push_back(&productos.at(0));

    for (const Producto* producto : vista) {
        if (producto != nullptr) {
            cout << producto->consultarNombre() << "\n";
        }
    }
    cout << "Primer objeto del inventario: " << productos.at(0).consultarNombre() << "\n";
}

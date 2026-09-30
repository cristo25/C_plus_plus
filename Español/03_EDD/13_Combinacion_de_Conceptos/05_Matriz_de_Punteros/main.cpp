// 5. Un arreglo de arreglos de punteros
//
// Vamos a organizar las tarjetas en filas y columnas. Producto* casillas[2][2] representa dos filas
// de dos direcciones. Con casillas[0][1] elegimos una tarjeta; si no es nullptr, podemos seguirla
// hasta el producto. Dos casillas pueden mostrar el mismo producto, como dos letreros que señalan
// la misma tienda. En este ejemplo añadimos const después de * para fijar las tarjetas; todavía
// podemos modificar los productos señalados. No confundimos una matriz con Producto**: la matriz
// contiene sus filas, mientras que el doble puntero guarda una dirección hacia otro puntero.
//
// Práctica: Vamos a crear una vitrina de tarjetas en filas.
// - Usemos una matriz de punteros con una casilla vacía.
// - Mostremos un mismo producto en dos casillas y contemos las ocupadas.

#include <iostream>
#include "../../../02_POO/08_Headers/Producto.h"

using namespace std;
using namespace curso;

int main() {
    Producto productos[2]{
        Producto("Cuaderno", 300),
        Producto("Lapiz", 100)
    };
    Producto* const casillas[2][2]{
        {&productos[0], nullptr},
        {&productos[1], &productos[0]}
    };

    // const protege las tarjetas de la matriz, no sus destinos. Este destino conocido existe.
    *casillas[0][0] = Producto("Cuaderno grande", 400);
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

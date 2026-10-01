// 4. Un vector de punteros: una vista del inventario
//
// Vamos a seleccionar productos sin copiarlos. Guardamos los productos en un arreglo y sus
// direcciones en vector<Producto*>. A esa selección la llamamos vista: puede crecer o mostrar un
// producto varias veces sin crear productos nuevos. Con Producto*& damos a seleccionar otra
// etiqueta del puntero original, por lo que puede cambiar su destino. Si recibiera solo Producto*,
// cambiaría una copia de la tarjeta. Aunque crezca el vector de direcciones, estos productos del
// arreglo permanecen en su lugar; deben seguir existiendo mientras los consultamos.
//
// Práctica: Vamos a seleccionar productos mediante sus direcciones.
// - Guardemos productos en un arreglo y direcciones en un vector.
// - Cambiemos una selección sin copiar los productos.

#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>
#include "../../../02_POO/08_Headers/Producto.h"

using namespace std;
using namespace curso;

void seleccionar(Producto*& seleccion, Producto& nuevoDestino) {
    seleccion = &nuevoDestino;
}

int main() {
    Producto productos[3]{
        Producto("Cuaderno", 300),
        Producto("Lapiz", 100),
        Producto("Libro", 500)
    };
    vector<Producto*> vista{&productos[0], &productos[1]};
    // Con vista[0] usamos la primera tarjeta guardada; podemos cambiar a qué producto señala.
    seleccionar(vista[0], productos[2]);
    vista.push_back(&productos[0]);

    for (const Producto* producto : vista) {
        if (producto != nullptr) {
            cout << producto->consultarNombre() << "\n";
        }
    }
    cout << "Primer objeto del inventario: " << productos[0].consultarNombre() << "\n";
}

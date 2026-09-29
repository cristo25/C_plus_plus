// 1. Un arreglo que contiene objetos
//
// Vamos a guardar objetos completos en un arreglo. En Producto productos[3] cada compartimento
// contiene un producto con su nombre y precio. Reutilizamos Producto.h, que ya estudiamos en POO.
// Podemos imaginar un cajón con tres bloques de Minecraft: cada bloque conserva sus propios datos,
// aunque todos tengan el mismo tipo. Recorremos los productos mediante const Producto& para leer el
// original sin copiarlo ni cambiarlo. Cuando termina el arreglo también terminan los objetos que
// contiene.
//

#include <iostream>
#include "../../../02_POO/08_Headers/Producto.h"

using namespace std;
using namespace curso;

int main() {
    const Producto productos[3]{
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

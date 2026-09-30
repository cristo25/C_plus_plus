// Const, headers y compilación de varios archivos
//
// Vamos a separar una clase para poder usarla desde varios programas. En Producto.h mostramos qué
// datos guarda y qué operaciones ofrece; en Producto.cpp escribimos cómo trabajan esas operaciones.
// Desde main creamos un Producto con nombre y precio. Guardamos el precio en centavos enteros para
// evitar pequeñas diferencias de los decimales. Con const protegemos el objeto y sus consultas.

#include "Producto.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    // Un objeto const solo permite llamar métodos que respeten su estado, como estas consultas.
    const Producto cuaderno("Cuaderno", 1250);

    cout << cuaderno.consultarNombre() << ": " << cuaderno.consultarPrecio() << " centavos\n";
}

// Práctica: vamos a ampliar el ejemplo con un segundo producto.
// - Declaramos ambos objetos como const y les damos nombres y precios diferentes.
// - Mostramos sus datos usando las funciones declaradas en Producto.h.
// - Explicamos por qué no podemos cambiar directamente un dato privado.

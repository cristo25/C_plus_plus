// 2. Un struct contiene una clase; un arreglo contiene esos structs
//
// Vamos a añadir la cantidad disponible a cada producto. Con struct Registro juntamos un Producto y
// un entero cantidad; después guardamos varias fichas Registro en un arreglo. Podemos imaginar un
// compartimento que contiene el producto y una etiqueta con sus existencias. Con
// registros[0].producto llegamos al objeto y con registros[0].cantidad al número. recibirUnidad
// recibe Registro& para cambiar la ficha original: si quitamos &, cambiaríamos solo una copia.
//
// Práctica: Vamos a guardar fichas con producto y cantidad.
// - Creemos un struct con Producto y cantidad, y guardemos varias fichas.
// - Cambiemos una cantidad mediante una función con referencia.

#include <iostream>
// Consultamos con numeric_limits el mayor entero permitido antes de sumar.
#include <limits>
// Avisamos de errores con mensajes, por ejemplo invalid_argument para un dato inválido.
#include <stdexcept>
#include "../../../02_POO/08_Headers/Producto.h"

using namespace std;
using namespace curso;

struct Registro {
    Producto producto;
    int cantidad;
};

void recibirUnidad(Registro& registro) {
    // La validación impide cantidades negativas y desbordar el entero al sumar uno.
    if (registro.cantidad < 0 || registro.cantidad == numeric_limits<int>::max()) {
        throw invalid_argument("Cantidad invalida");
    }
    ++registro.cantidad;
}

int main() {
    Registro registros[2]{
        Registro{Producto("Cuaderno", 300), 2},
        Registro{Producto("Lapiz", 100), 5}
    };

    recibirUnidad(registros[0]);
    for (const Registro& registro : registros) {
        cout << registro.producto.consultarNombre() << ": " << registro.cantidad << "\n";
    }
}

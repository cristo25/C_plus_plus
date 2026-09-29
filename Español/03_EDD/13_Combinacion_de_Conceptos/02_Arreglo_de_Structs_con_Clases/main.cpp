// 2. Un struct contiene una clase; un arreglo contiene esos structs
//
// Queremos guardar existencias además del producto. Registro reúne un Producto
// y una cantidad: el compartimento del cajón contiene una ficha completa con
// esos dos datos. class y struct pueden contenerse entre sí; su diferencia
// principal es el acceso por defecto. Usamos una clase para las reglas del
// producto y un struct sencillo para agruparlo con su cantidad. Una función
// recibe Registro& para modificar la ficha real del arreglo.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../../02_POO/08_Headers/Producto.cpp -o programa.exe
// Ejecutar: ./programa.exe
//
// Practica: Cambia Registro& por Registro. Predice y explica qué cantidad se imprime.

#include <array>
#include <iostream>
#include <limits>
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
    array<Registro, 2> registros{
        Registro{Producto("Cuaderno", 300), 2},
        Registro{Producto("Lapiz", 100), 5}
    };

    recibirUnidad(registros.at(0));
    for (const Registro& registro : registros) {
        cout << registro.producto.consultarNombre() << ": " << registro.cantidad << "\n";
    }
}

// 7. Un vector de propietarios y un puntero observador
//
// vector<unique_ptr<Producto>> contiene tarjetas que además son responsables
// de destruir sus productos. make_unique crea el objeto administrado. get()
// presta su dirección, pero no entrega la propiedad. Al reubicar el vector
// se mueven los propietarios; los productos administrados conservan su ubicación.
// En cambio, vector<Producto> puede mover los objetos y dejar colgando sus punteros
// al realocar. Borrar un unique_ptr destruye su producto: antes retiramos su
// observador. Si hubiera más observadores, tendríamos que retirar todos.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../../02_POO/08_Headers/Producto.cpp -o programa.exe
// Ejecutar: ./programa.exe
//
// Practica: Añade un segundo observador y explica cuándo debes retirarlo también.

#include <iostream>
#include <memory>
#include <vector>
#include "../../../02_POO/08_Headers/Producto.h"

using namespace std;
using namespace curso;

int main() {
    vector<unique_ptr<Producto>> propietarios;
    propietarios.push_back(make_unique<Producto>("Cuaderno", 300));
    const Producto* observador = propietarios.at(0).get();

    // Una capacidad mayor obliga a realocar las tarjetas, no los productos que administran.
    propietarios.reserve(propietarios.capacity() + 1);
    propietarios.push_back(make_unique<Producto>("Lapiz", 100));
    cout << boolalpha << "El producto sigue en el mismo sitio: " << (observador == propietarios.at(0).get()) << "\n";
    cout << observador->consultarNombre() << "\n";

    // No desreferencies el observador después de borrar su propietario.
    observador = nullptr;
    propietarios.erase(propietarios.begin());
    cout << "Propietarios restantes: " << propietarios.size() << "\n";
}

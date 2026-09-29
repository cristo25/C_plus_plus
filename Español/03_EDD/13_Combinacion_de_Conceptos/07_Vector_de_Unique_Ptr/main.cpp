// 7. Un vector de propietarios y un puntero observador
//
// Vamos a separar la ubicación de las tarjetas y la de los productos. En
// vector<unique_ptr<Producto>> cada tarjeta también tiene la responsabilidad de liberar su
// producto. Cuando el vector necesita más espacio puede mover las tarjetas; los productos creados
// aparte conservan sus direcciones. Con get prestamos una dirección, pero no la responsabilidad de
// borrar. Al eliminar la tarjeta responsable también se destruye el producto; antes dejamos de usar
// todos los punteros prestados. Esto es distinto de vector<Producto>, donde al crecer pueden
// mudarse los productos mismos.
//

#include <iostream>
// Usamos unique_ptr para liberar automáticamente el objeto que administra.
#include <memory>
// Guardamos una colección que puede crecer con vector.
#include <vector>
#include "../../../02_POO/08_Headers/Producto.h"

using namespace std;
using namespace curso;

int main() {
    vector<unique_ptr<Producto>> propietarios;
    propietarios.push_back(make_unique<Producto>("Cuaderno", 300));
    const Producto* observador = propietarios.at(0).get();

    // Pedimos más espacio al vector: se mudan sus tarjetas, mientras los productos siguen donde
    // estaban.
    propietarios.reserve(propietarios.capacity() + 1);
    propietarios.push_back(make_unique<Producto>("Lapiz", 100));
    cout << boolalpha << "El producto sigue en el mismo sitio: " << (observador == propietarios.at(0).get()) << "\n";
    cout << observador->consultarNombre() << "\n";

    // Dejamos de seguir esta dirección antes de liberar el producto que señalaba.
    observador = nullptr;
    propietarios.erase(propietarios.begin());
    cout << "Propietarios restantes: " << propietarios.size() << "\n";
}

// 9. Un vector contiene clases que administran nodos
//
// Vamos a guardar varios estantes en un vector. Dentro de cada estante hay nodos y dentro de cada
// nodo un producto: seguimos esas capas una a una. Al crecer el vector puede mudarse un estante,
// por lo que retiramos los punteros al propio estante antes de forzar ese cambio. Sus nodos se
// crearon aparte y no se mudan al transferir quién los administra. Por eso podemos conservar una
// consulta a un nodo mientras siga existiendo. Si vaciamos su estante, el nodo desaparece y debemos
// dejar de usar esa consulta.
//

#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>
#include "../Estante.h"

using namespace std;
using namespace curso;

int main() {
    vector<Estante> estantes;
    estantes.emplace_back("Papeleria");
    estantes.at(0).agregar(Producto("Cuaderno", 300));

    Estante* direccionEstante = &estantes.at(0);
    const Estante::Nodo* direccionNodo = direccionEstante->primero();
    cout << "Antes de crecer: " << direccionEstante->consultarNombre() << "\n";

    // Retiramos la tarjeta al estante antes de forzar su reubicación; no la reutilizamos.
    direccionEstante = nullptr;
    estantes.reserve(estantes.capacity() + 1);
    estantes.emplace_back("Libros");
    estantes.at(1).agregar(Producto("Libro", 500));

    // Este nodo sigue vivo, con el mismo responsable de liberar el nodo y la misma dirección.
    cout << boolalpha << "Nodo en el mismo sitio: " << (direccionNodo == estantes.at(0).primero()) << "\n";
    cout << direccionNodo->consultarProducto().consultarNombre() << "\n";
    for (const Estante& estante : estantes) {
        cout << estante.consultarNombre() << ": " << estante.valorTotal() << "\n";
    }

    // Vaciar destruye los nodos: retiramos antes el observador de esta lista.
    direccionNodo = nullptr;
    estantes.at(0).vaciar();
}

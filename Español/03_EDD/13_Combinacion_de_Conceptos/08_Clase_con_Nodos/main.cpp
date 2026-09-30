// 8. Una clase administra nodos struct
//
// Vamos a reunir la cadena y sus reglas dentro de Estante. Cada nodo contiene un Producto y un
// unique_ptr al siguiente; el estante se encarga del primero. Desde fuera pedimos agregar o
// consultar, sin cambiar directamente los enlaces. Podemos imaginar un encargado de estantería que
// acomoda las cajas y nos presta sus etiquetas para leerlas. primero() y siguienteNodo() prestan
// direcciones; consultarProducto() presta una referencia de lectura. Cuando vaciamos el estante,
// esas consultas dejan de servir porque sus cajas ya no existen.
//
// Práctica: Vamos a administrar una lista de productos dentro de una clase.
// - Agreguemos tres productos mediante la clase Estante.
// - Recorramos sus nodos, sumemos precios y vaciemos la lista.

#include <iostream>
#include "../Estante.h"

using namespace std;
using namespace curso;

int main() {
    Estante estante("Papeleria");
    estante.agregar(Producto("Cuaderno", 300));
    estante.agregar(Producto("Lapiz", 100));

    const Estante::Nodo* actual = estante.primero();
    while (actual != nullptr) {
        cout << actual->consultarProducto().consultarNombre() << "\n";
        actual = actual->siguienteNodo();
    }
    cout << "Total en centavos: " << estante.valorTotal() << "\n";
}

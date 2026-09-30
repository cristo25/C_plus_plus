// Lista circular
//
// Vamos a cerrar la cadena formando un círculo: el último nodo vuelve al primero. Podemos
// imaginar turnos de jugadores que se repiten. Como no encontramos nullptr al dar la vuelta,
// detenemos el recorrido al regresar al inicio. Guardamos el último nodo para añadir otro con
// pocos cambios. Al quitar el único nodo dejamos la lista vacía; al quitar otro conservamos
// cerrado el círculo.
//
// Práctica: Vamos a crear una ronda de turnos con una lista circular.
// - Agreguemos tres participantes y mostremos una vuelta completa.
// - Quitemos un participante y detengamos el recorrido al volver al inicio.

#include "ListaCircular.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    ListaCircular turnos;
    if (!(turnos.valores().empty() && !turnos.eliminar(1))) {
        return 1;
    }
    // El último apunta al primero. valores() devuelve solo una vuelta para evitar un ciclo
    // infinito.
    turnos.agregar(1);
    turnos.agregar(2);
    turnos.agregar(3);
    if (turnos.eliminar(9)) {
        return 1;
    }
    if (!(turnos.eliminar(2))) {
        return 1;
    }

    for (int turno : turnos.valores()) {
        cout << turno << ' ';
    }
    cout << "\n";
    if (!(turnos.eliminar(3) && turnos.eliminar(1))) {
        return 1;
    }

    turnos.agregar(4);
}

#include "ListaCircular.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    ListaCircular turnos;
    if (!(turnos.valores().empty() && !turnos.eliminar(1))) {
        return 1;
    }
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

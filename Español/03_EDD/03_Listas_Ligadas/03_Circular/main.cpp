// Lista circular
//
// El último nodo apunta al primero. Debes detenerte al volver al inicio; esperar nullptr
// causaría un ciclo infinito. La inserción al final cuesta O(1); buscar y eliminar por valor
// cuestan O(n). Esta variante es simplemente ligada y circular.
//
// Analogía: Una rueda de turnos: después de la última persona regresas a la primera.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Dibuja el caso de un solo nodo: apunta a sí mismo. Explica por qué necesita un caso
// especial al eliminarlo.

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

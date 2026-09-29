// Propiedad con unique_ptr
//
// unique_ptr tiene un propietario y libera el objeto automáticamente. make_unique lo construye.
// move transfiere la propiedad; no copies un unique_ptr. Usa punteros crudos cuando solo
// observes un objeto y su vida esté garantizada.
//
// Analogía: Una llave única administra el casillero. Cuando entregas la llave, el dueño anterior
// deja de tenerla.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Usa reset() y comprueba que el propietario queda vacío. No uses el observador
// después.

#include <iostream>
#include <memory>
#include <utility>

using namespace std;

int main() {
    auto propietario = make_unique<int>(42);
    // El observador accede al dato, pero no lo libera: no debe usar delete.
    int* observador = propietario.get();
    // move transfiere la propiedad; el dueño anterior queda vacío y el dato sigue vivo.
    auto nuevoPropietario = move(propietario);

    cout << *observador << "\n";
} // nuevoPropietario libera el entero; observador deja de ser valido.

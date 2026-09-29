// 9. Un vector contiene clases que administran nodos
//
// vector<Estante> guarda estantes completos. Cada estante es dueño de una lista;
// cada nodo struct guarda un Producto y es dueño del siguiente. Al crecer el
// vector puede mover los estantes: un Estante* a un elemento deja de ser válido.
// Los nodos administrados conservan su dirección porque se transfiere su propiedad.
// Estante no se copia: copiar requeriría duplicar la cadena. Su movimiento noexcept
// permite que el vector lo reubique. Una referencia también quedaría invalidada
// si se refiriera al estante reubicado; no adquiere estabilidad por ser referencia.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../../02_POO/08_Headers/Producto.cpp -o programa.exe
// Ejecutar: ./programa.exe
//
// Practica: Añade otro estante después de reserve y comprueba desde el vector el nodo prestado.

#include <iostream>
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

    // Este nodo sigue vivo, con el mismo propietario lógico y la misma dirección.
    cout << boolalpha << "Nodo en el mismo sitio: " << (direccionNodo == estantes.at(0).primero()) << "\n";
    cout << direccionNodo->consultarProducto().consultarNombre() << "\n";
    for (const Estante& estante : estantes) {
        cout << estante.consultarNombre() << ": " << estante.valorTotal() << "\n";
    }

    // Vaciar destruye los nodos: retiramos antes el observador de esta lista.
    direccionNodo = nullptr;
    estantes.at(0).vaciar();
}

// 8. Una clase administra nodos struct
//
// Estante combina POO y listas: oculta una cadena de nodos struct; cada nodo
// contiene una clase Producto y es dueño del siguiente mediante unique_ptr.
// El estante posee el primer nodo. Los enlaces se cambian dentro de la clase.
// primero() presta const Nodo*, y consultarProducto() presta const Producto&.
// La vista prestada no puede sobrevivir a vaciar() ni a destruir el estante.
// Lee Estante.h: el header tiene la implementación compartida para estos ejemplos.
// Producto.cpp sigue enlazándose porque sus funciones se definieron fuera del header.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../../02_POO/08_Headers/Producto.cpp -o programa.exe
// Ejecutar: ./programa.exe
//
// Practica: Agrega tres productos y predice su orden. Dibuja la cadena de propietarios.

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

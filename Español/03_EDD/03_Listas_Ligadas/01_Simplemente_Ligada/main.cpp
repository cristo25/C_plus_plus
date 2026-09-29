// Lista simplemente ligada
//
// Cada nodo guarda un dato y la dirección del siguiente. El último apunta a nullptr. Para llegar a
// otro nodo seguimos los enlaces uno por uno. Recorrer la lista o buscar un valor puede exigir
// visitar sus n nodos (O(n)); aquí n es la cantidad de nodos. El header implementa inserción al
// final, eliminación de la primera coincidencia y liberación de todos los nodos.
//
// Analogía: Una búsqueda del tesoro: cada tarjeta contiene un dato y la pista hacia la
// siguiente. La última dice «fin».
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Dibuja los enlaces antes y después de eliminar el primer nodo. Agrega un método
// contiene.

#include "ListaSimple.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    ListaSimple lista;
    if (!(lista.valores().empty() && !lista.eliminar(99))) {
        return 1;
    }
    // Los nodos formarán la cadena 10 -> 20 -> 30; los enlaces se implementan en el header.
    lista.agregar(10);
    lista.agregar(20);
    lista.agregar(30);
    if (!(lista.eliminar(20))) {
        return 1;
    }

    for (int dato : lista.valores()) {
        cout << dato << ' ';
    }
    cout << "\n";
    if (!(lista.eliminar(10) && lista.eliminar(30))) {
        return 1;
    }
}

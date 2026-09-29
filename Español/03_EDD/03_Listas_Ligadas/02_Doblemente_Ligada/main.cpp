// Lista doblemente ligada
//
// Cada nodo conoce al anterior y al siguiente. Guardar inicio y fin permite agregar al final en
// O(1) y recorrer en ambos sentidos. Buscar un valor sigue siendo O(n); borrar un nodo ya
// localizado requiere ajustar ambos enlaces.
//
// Analogía: Los vagones de un tren están enganchados por delante y por detrás; puedes caminar en
// ambos sentidos.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Dibuja los dos enlaces que cambian al borrar un nodo del medio.

#include "ListaDoble.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    ListaDoble lista;
    // El enlace al anterior permite recorrer desde el final: 30, 20, 10.
    if (!(lista.inversos().empty() && !lista.eliminar(5))) {
        return 1;
    }
    lista.agregar(10);
    lista.agregar(20);
    lista.agregar(30);

    for (int dato : lista.inversos()) {
        cout << dato << ' ';
    }
    cout << "\n";
    if (!(lista.eliminar(20))) {
        return 1;
    }

    if (!(lista.eliminar(10) && lista.eliminar(30))) {
        return 1;
    }

    lista.agregar(40);
}

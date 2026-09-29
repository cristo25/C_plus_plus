// Recorridos de un árbol
//
// Preorden visita raíz, izquierda, derecha. Inorden visita izquierda, raíz, derecha. Postorden
// visita izquierda, derecha, raíz. En un ABB, inorden produce valores ordenados. Los recorridos
// visitan todos los nodos: O(n), con O(h) de pila recursiva más el vector de salida.
//
// Analogía: Recorres una casa: puedes registrar el cuarto antes de visitar sus anexos, entre
// ambos anexos o al terminar de visitarlos.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Dibuja el árbol y reproduce cada recorrido con flechas antes de ejecutarlo.

#include "../Arbol.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    Arbol arbol;
    for (int dato : {4, 2, 6, 1, 3, 5, 7}) {
        arbol.insertar(dato);
    }

    // Preorden: raíz primero. Inorden: raíz entre ramas. Postorden: raíz al final.
    for (Recorrido orden : {Recorrido::Preorden, Recorrido::Inorden, Recorrido::Postorden}) {
        for (int dato : arbol.valores(orden)) {
            cout << dato << ' ';
        }
        cout << "\n";
    }
}

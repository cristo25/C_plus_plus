// Árboles
//
// Distingue árbol binario de ABB y después estudia sus recorridos. El integrador inserta, busca,
// recorre y elimina. Los ejemplos recursivos usan árboles pequeños; balanceo y recorridos
// iterativos son ampliaciones para grandes profundidades.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe

#include "Arbol.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    Arbol arbol;
    // assert comprueba un resultado del integrador; no realiza operaciones del programa.
    assert(arbol.valores().empty());
    for (int dato : {5, 3, 7, 2, 4, 6, 8}) {
        if (!(arbol.insertar(dato))) {
            return 1;
        }
    }
    assert(arbol.contiene(4));
    // El árbol es el mismo; cambiamos cuándo se visita la raíz respecto de sus dos ramas.
    for (Recorrido orden : {Recorrido::Preorden, Recorrido::Inorden, Recorrido::Postorden}) {
        for (int dato : arbol.valores(orden)) {
            cout << dato << ' ';
        }
        cout << "\n";
    }
    if (!(arbol.eliminar(5))) {
        return 1;
    }
    assert((arbol.valores() == vector<int>{2, 3, 4, 6, 7, 8}));
    for (int dato : {2, 3, 4, 6, 7, 8}) {
        if (!(arbol.eliminar(dato))) {
            return 1;
        }
    }
    assert(arbol.valores().empty());
}

// Árbol binario: raíces, hijos y hojas
//
// Un árbol conecta nodos sin ciclos. La raíz no tiene padre; una hoja no tiene hijos. Un árbol
// binario admite como máximo dos hijos por nodo. No todo árbol binario ordena sus valores.
//
// Analogía: Un organigrama empieza en un responsable y se divide en ramas. En este ejemplo cada
// responsable tiene como máximo dos subordinados.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Dibuja el árbol, identifica sus hojas y agrega un nieto.

#include <iostream>
#include <memory>

using namespace std;

struct Nodo {
    int dato;
    unique_ptr<Nodo> izquierdo;
    unique_ptr<Nodo> derecho;
    explicit Nodo(int valor) : dato(valor) {
    }
};

int contar(const Nodo* nodo) {
    // Una rama vacía aporta cero; cada nodo suma uno más los nodos de sus dos hijos.
    if (!nodo) {
        return 0;
    }
    return 1 + contar(nodo->izquierdo.get()) + contar(nodo->derecho.get());
}

int main() {
    auto raiz = make_unique<Nodo>(10);
    raiz->izquierdo = make_unique<Nodo>(20); // Binario, sin regla de busqueda.
    raiz->derecho = make_unique<Nodo>(5);

    cout << "Nodos: " << contar(raiz.get()) << "\n";
}

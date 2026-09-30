// Árbol binario: raíces, hijos y hojas
//
// Vamos a unir nodos formando ramas. En un árbol binario cada nodo puede tener como máximo un hijo
// izquierdo y uno derecho. Al primer nodo lo llamamos raíz; a uno sin hijos lo llamamos hoja. Aquí
// solo estamos construyendo la forma: tener dos ramas no obliga a ordenar los números. Para contar,
// sumamos el nodo actual y los de sus dos ramas mediante recursión. Usamos unique_ptr para que cada
// rama libere sus nodos al terminar.
//
// Práctica: Vamos a dibujar un árbol binario con nodos.
// - Creemos una raíz, dos hijos y al menos una hoja más.
// - Contemos los nodos recorriendo ambas ramas.

#include <iostream>
// Usamos unique_ptr para liberar automáticamente el objeto que administra.
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

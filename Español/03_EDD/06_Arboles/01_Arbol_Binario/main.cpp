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

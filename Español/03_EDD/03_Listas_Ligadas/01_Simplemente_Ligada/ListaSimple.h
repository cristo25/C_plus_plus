#ifndef CURSO_LISTA_SIMPLE_H
#define CURSO_LISTA_SIMPLE_H
#include <vector>

namespace curso {
    using namespace std;

    class ListaSimple {
        struct Nodo {
            int dato;
            Nodo* siguiente;
        };
        Nodo* inicio = nullptr;

    public:
        ListaSimple() = default;
        ListaSimple(const ListaSimple&) = delete; // No duplicar propietarios de nodos.
        ListaSimple& operator=(const ListaSimple&) = delete;
        ~ListaSimple() {
            while (inicio) {
                Nodo* siguiente = inicio->siguiente;
                delete inicio;
                inicio = siguiente;
            }
        }
        void agregar(int dato) {
            Nodo* nuevo = new Nodo{dato, nullptr};
            if (!inicio) {
                inicio = nuevo;
                return;
            }
            // ponytail: insertar al final cuesta O(n); guardar cola si importa el costo.
            Nodo* actual = inicio;
            while (actual->siguiente) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
        bool eliminar(int dato) {
            Nodo* actual = inicio;
            Nodo* anterior = nullptr;
            while (actual && actual->dato != dato) {
                anterior = actual;
                actual = actual->siguiente;
            }
            if (!actual) {
                return false;
            }
            if (anterior) {
                anterior->siguiente = actual->siguiente;
            } else {
                inicio = actual->siguiente;
            }
            delete actual;
            return true;
        }
        vector<int> valores() const {
            vector<int> resultado;
            for (Nodo* actual = inicio; actual; actual = actual->siguiente) {
                resultado.push_back(actual->dato);
            }
            return resultado;
        }
    };
} // namespace curso

#endif

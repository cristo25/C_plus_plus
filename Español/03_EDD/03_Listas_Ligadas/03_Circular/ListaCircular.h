#ifndef CURSO_LISTA_CIRCULAR_H
#define CURSO_LISTA_CIRCULAR_H
#include <vector>

namespace curso {
    using namespace std;

    class ListaCircular {
        struct Nodo {
            int dato;
            Nodo* siguiente;
        };
        Nodo* fin = nullptr; // El inicio es fin->siguiente cuando hay nodos.
    public:
        ListaCircular() = default;
        ListaCircular(const ListaCircular&) = delete;
        ListaCircular& operator=(const ListaCircular&) = delete;
        ~ListaCircular() {
            if (!fin) {
                return;
            }
            Nodo* actual = fin->siguiente;
            fin->siguiente = nullptr; // Abre el anillo para destruirlo como una cadena.
            while (actual) {
                Nodo* siguiente = actual->siguiente;
                delete actual;
                actual = siguiente;
            }
        }
        void agregar(int dato) {
            Nodo* nuevo = new Nodo{dato, nullptr};
            if (!fin) {
                // Con un único nodo, el siguiente enlace apunta al propio nodo.
                nuevo->siguiente = nuevo;
            } else {
                nuevo->siguiente = fin->siguiente;
                fin->siguiente = nuevo;
            }
            fin = nuevo;
        }
        bool eliminar(int dato) {
            if (!fin) {
                return false;
            }
            Nodo* anterior = fin;
            Nodo* actual = fin->siguiente;
            do {
                if (actual->dato == dato) {
                    // Este caso detecta el único nodo; al quitarlo, la lista pasa a estar vacía.
                    if (actual == anterior) {
                        fin = nullptr;
                    } else {
                        anterior->siguiente = actual->siguiente;
                        if (actual == fin) {
                            fin = anterior;
                        }
                    }
                    delete actual;
                    return true;
                }
                anterior = actual;
                actual = actual->siguiente;
            // Detenemos la vuelta al regresar al inicio; no habrá un nullptr al final del
            // anillo.
            } while (actual != fin->siguiente);
            return false;
        }
        vector<int> valores() const {
            vector<int> resultado;
            if (!fin) {
                return resultado;
            }
            Nodo* actual = fin->siguiente;
            do {
                resultado.push_back(actual->dato);
                actual = actual->siguiente;
            } while (actual != fin->siguiente);
            return resultado;
        }
    };
} // namespace curso

#endif

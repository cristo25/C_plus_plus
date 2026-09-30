// Con = delete impedimos copiar la clase para no dejar dos objetos intentando liberar los mismos
// nodos.

#ifndef CURSO_LISTA_DOBLE_H
#define CURSO_LISTA_DOBLE_H
// Guardamos una colección que puede crecer con vector.
#include <vector>

namespace curso {
    using namespace std;

    class ListaDoble {
        // Cada vagón conoce al de delante y al de detrás: podemos viajar en ambos sentidos.
        struct Nodo {
            int dato;
            Nodo* anterior;
            Nodo* siguiente;
        };
        Nodo* inicio = nullptr;
        Nodo* fin = nullptr;

    public:
        ListaDoble() = default;
        ListaDoble(const ListaDoble&) = delete;
        ListaDoble& operator=(const ListaDoble&) = delete;
        ~ListaDoble() {
            while (inicio) {
                Nodo* siguiente = inicio->siguiente;
                delete inicio;
                inicio = siguiente;
            }
        }
        void agregar(int dato) {
            // Conservar fin permite anexar ajustando unos pocos enlaces, sin recorrer los demás
 // nodos.
            Nodo* nuevo = new Nodo{dato, fin, nullptr};
            if (fin) {
                fin->siguiente = nuevo;
            } else {
                inicio = nuevo;
            }
            fin = nuevo;
        }
        bool eliminar(int dato) {
            Nodo* actual = inicio;
            while (actual && actual->dato != dato) {
                actual = actual->siguiente;
            }
            if (!actual) {
                return false;
            }
            // Al eliminar, hay que reparar ambos vecinos y actualizar inicio o fin si son
            // extremos.
            if (actual->anterior) {
                actual->anterior->siguiente = actual->siguiente;
            } else {
                inicio = actual->siguiente;
            }
            if (actual->siguiente) {
                actual->siguiente->anterior = actual->anterior;
            } else {
                fin = actual->anterior;
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
        vector<int> inversos() const {
            vector<int> resultado;
            // El recorrido inverso empieza por fin y sigue los enlaces al anterior.
            for (Nodo* actual = fin; actual; actual = actual->anterior) {
                resultado.push_back(actual->dato);
            }
            return resultado;
        }
    };
} // namespace curso

#endif

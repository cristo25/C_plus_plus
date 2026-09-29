// Con = delete impedimos copiar la clase para no dejar dos objetos intentando liberar los mismos
// nodos.

#ifndef CURSO_LISTA_SIMPLE_H
#define CURSO_LISTA_SIMPLE_H
// Guardamos una colección que puede crecer con vector.
#include <vector>

namespace curso {
    using namespace std;

    class ListaSimple {
        // Cada tarjeta guarda un valor y la dirección de la siguiente; nullptr termina la
        // cadena.
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
                // Guardamos el siguiente enlace antes de destruir el nodo; después de delete no
                // se puede leer.
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
            // ponytail: para agregar recorremos todos los nodos hasta el último; guardar un puntero
            // al último evita ese recorrido.
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
                // El nodo anterior salta al siguiente del eliminado: reparamos la cadena antes
                // de liberar memoria.
                anterior->siguiente = actual->siguiente;
            } else {
                // Si se elimina el primero, la entrada de la lista debe apuntar al segundo.
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

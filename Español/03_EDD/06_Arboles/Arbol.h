#ifndef CURSO_ARBOL_H
#define CURSO_ARBOL_H
// Usamos unique_ptr para liberar automáticamente el objeto que administra.
#include <memory>
// Guardamos una colección que puede crecer con vector.
#include <vector>

namespace curso {
    using namespace std;

    enum class Recorrido {
        Preorden,
        Inorden,
        Postorden
    };

    class Arbol {
        struct Nodo {
            int dato;
            unique_ptr<Nodo> izquierdo;
            unique_ptr<Nodo> derecho;
            explicit Nodo(int valor) : dato(valor) {
            }
        };
        unique_ptr<Nodo> raiz;

        // La referencia al unique_ptr permite crear o sustituir el dueño de una rama.
        static bool insertarEn(unique_ptr<Nodo>& nodo, int dato) {
            if (!nodo) {
                nodo = make_unique<Nodo>(dato);
                return true;
            }
            if (dato == nodo->dato) {
                return false;
            }
            return insertarEn(dato < nodo->dato ? nodo->izquierdo : nodo->derecho, dato);
        }
        static bool eliminarEn(unique_ptr<Nodo>& nodo, int dato) {
            if (!nodo) {
                return false;
            }
            if (dato < nodo->dato) {
                return eliminarEn(nodo->izquierdo, dato);
            }
            if (dato > nodo->dato) {
                return eliminarEn(nodo->derecho, dato);
            }
            // Cero o un hijo: intercambiamos tarjetas con swap, sin copiar los nodos.
            if (!nodo->izquierdo) {
                unique_ptr<Nodo> reemplazo;
                reemplazo.swap(nodo->derecho);
                nodo.swap(reemplazo);
            } else if (!nodo->derecho) {
                unique_ptr<Nodo> reemplazo;
                reemplazo.swap(nodo->izquierdo);
                nodo.swap(reemplazo);
            } else {
                // Con dos hijos, el menor de la rama derecha sustituye el dato sin romper el
                // orden del ABB.
                const Nodo* sucesor = nodo->derecho.get();
                while (sucesor->izquierdo) {
                    sucesor = sucesor->izquierdo.get();
                }
                nodo->dato = sucesor->dato;
                eliminarEn(nodo->derecho, sucesor->dato);
            }
            return true;
        }
        // La posición de push_back respecto de ambas llamadas define preorden, inorden o
        // postorden.
        static void recorrer(const Nodo* nodo, Recorrido orden, vector<int>& salida) {
            if (!nodo) {
                return;
            }
            if (orden == Recorrido::Preorden) {
                salida.push_back(nodo->dato);
            }
            recorrer(nodo->izquierdo.get(), orden, salida);
            if (orden == Recorrido::Inorden) {
                salida.push_back(nodo->dato);
            }
            recorrer(nodo->derecho.get(), orden, salida);
            if (orden == Recorrido::Postorden) {
                salida.push_back(nodo->dato);
            }
        }

    public:
        // Nuestro árbol no se acomoda solo: al agregar números ordenados puede parecer una cadena.
        bool insertar(int dato) {
            return insertarEn(raiz, dato);
        }
        bool eliminar(int dato) {
            return eliminarEn(raiz, dato);
        }
        bool contiene(int dato) const {
            const Nodo* actual = raiz.get();
            while (actual) {
                if (dato == actual->dato) {
                    return true;
                }
                actual = dato < actual->dato ? actual->izquierdo.get() : actual->derecho.get();
            }
            return false;
        }
        vector<int> valores(Recorrido orden = Recorrido::Inorden) const {
            vector<int> salida;
            recorrer(raiz.get(), orden, salida);
            return salida;
        }
    };
} // namespace curso

#endif

// Header compartido por los pasos 8, 9 y el integrador; las funciones definidas en la clase son inline.
#ifndef CURSO_ESTANTE_H
#define CURSO_ESTANTE_H

#include <limits>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include "../../02_POO/08_Headers/Producto.h"

namespace curso {
    using namespace std;

    class Estante {
    public:
        struct Nodo {
        private:
            Producto producto;
            unique_ptr<Nodo> siguiente;
            // Solo Estante cambia los enlaces; las consultas prestan una vista const del nodo.
            friend class Estante;

        public:
            // El parámetro se consulta por referencia, pero el nodo guarda su propia copia.
            explicit Nodo(const Producto& otro) : producto(otro) {
            }

            const Producto& consultarProducto() const {
                return producto;
            }

            const Nodo* siguienteNodo() const {
                return siguiente.get();
            }
        };

    private:
        string nombre;
        unique_ptr<Nodo> inicio;

    public:
        explicit Estante(string etiqueta) : nombre(move(etiqueta)) {
            if (nombre.empty()) {
                throw invalid_argument("El estante necesita un nombre");
            }
        }

        // No duplicamos propietarios. Mover transfiere la cadena y deja el inicio de origen nulo.
        Estante(const Estante&) = delete;
        Estante& operator=(const Estante&) = delete;
        Estante(Estante&&) noexcept = default;

        Estante& operator=(Estante&& otro) noexcept {
            if (this != &otro) {
                vaciar();
                nombre = move(otro.nombre);
                inicio = move(otro.inicio);
            }
            return *this;
        }

        ~Estante() {
            vaciar();
        }

        void agregar(const Producto& producto) {
            auto nuevoNodo = make_unique<Nodo>(producto);
            // Insertamos al principio: nuevo -> antigua cadena. Se invierte el orden de inserción.
            nuevoNodo->siguiente = move(inicio);
            inicio = move(nuevoNodo);
        }

        const string& consultarNombre() const {
            return nombre;
        }

        const Nodo* primero() const {
            return inicio.get();
        }

        long long valorTotal() const {
            long long valorTotal = 0;
            const Nodo* actual = primero();
            while (actual != nullptr) {
                const int precio = actual->consultarProducto().consultarPrecio();
                if (valorTotal > numeric_limits<long long>::max() - precio) {
                    throw overflow_error("El total supera el rango de long long");
                }
                valorTotal += precio;
                actual = actual->siguienteNodo();
            }
            return valorTotal;
        }

        void vaciar() noexcept {
            // Soltamos un nodo por vez, sin una cadena de destructores recursivos.
            while (inicio != nullptr) {
                // Separamos el resto antes de destruir el nodo actual al reemplazar inicio.
                auto siguiente = move(inicio->siguiente);
                inicio = move(siguiente);
            }
        }
    };
}

#endif

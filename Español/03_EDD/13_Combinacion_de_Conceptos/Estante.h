// Un solo estante se encarga de cada cadena de nodos para no borrarla dos veces.
//
// Desde fuera del estante podemos consultar los nodos, pero solo el estante cambia sus enlaces.
//
// Cuando un vector crece, puede cambiar de lugar un estante. Permitimos ese cambio sin copiar sus
// nodos: el nuevo estante se encarga de la misma cadena.

// Compartimos esta clase entre los pasos 8, 9 y el integrador. Podemos definir sus funciones dentro
// de la clase y usar el header desde varios archivos.
#ifndef CURSO_ESTANTE_H
#define CURSO_ESTANTE_H

// Consultamos con numeric_limits el mayor entero permitido antes de sumar.
#include <limits>
// Usamos unique_ptr para liberar automáticamente el objeto que administra.
#include <memory>
// Avisamos de errores con mensajes, por ejemplo invalid_argument para un dato inválido.
#include <stdexcept>
// Guardamos y trabajamos con texto mediante string.
#include <string>
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
        explicit Estante(const string& etiqueta) : nombre(etiqueta) {
            if (nombre.empty()) {
                throw invalid_argument("El estante necesita un nombre");
            }
        }

        // No duplicamos propietarios: cada cadena tiene un solo estante responsable.
        Estante(const Estante&) = delete;
        Estante& operator=(const Estante&) = delete;
        // Con && recibimos el estante que el vector cambia de casilla sin copiar sus nodos.
        Estante(Estante&&) noexcept = default;

        ~Estante() {
            vaciar();
        }

        void agregar(const Producto& producto) {
            auto nuevoNodo = make_unique<Nodo>(producto);
            // swap intercambia las tarjetas: el nuevo nodo señala al inicio anterior.
            nuevoNodo->siguiente.swap(inicio);
            inicio.swap(nuevoNodo);
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
                // Guardamos el nodo actual aparte y dejamos al siguiente como nuevo inicio.
                unique_ptr<Nodo> actual;
                actual.swap(inicio);
                inicio.swap(actual->siguiente);
            }
        }
    };
}

#endif

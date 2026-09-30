// Integrador: propietarios, vistas, matrices y ordenamiento
//
// Vamos a combinar las capas para mostrar productos ordenados sin mover sus cajas originales.
// Guardamos estantes en un vector; cada estante contiene nodos y cada nodo contiene un producto.
// Reunimos direcciones de esos nodos en vista y ordenamos solo las tarjetas por precio. Después
// elegimos tarjetas para una matriz de exposición. Una misma tarjeta puede aparecer varias veces:
// contar casillas ocupadas no significa contar productos distintos. Calculamos el valor total desde
// los estantes para no sumar dos veces un producto repetido en la vitrina.
//
// Práctica: Vamos a crear un inventario con estantes y vistas.
// - Guardemos productos en nodos de varios estantes.
// - Ordenemos direcciones para mostrar una vista sin cambiar las listas originales.

// Usamos sort para ordenar o cambiar el orden de los datos.
#include <algorithm>
#include <iostream>
// Consultamos con numeric_limits el mayor entero permitido antes de sumar.
#include <limits>
// Avisamos de errores con mensajes, por ejemplo invalid_argument para un dato inválido.
#include <stdexcept>
// Guardamos una colección que puede crecer con vector.
#include <vector>
#include "Estante.h"

using namespace std;
using namespace curso;

// Referencia a una tarjeta: cambiamos la selección del llamador. El destino es de lectura.
void seleccionar(const Estante::Nodo*& seleccion, const Estante::Nodo* nuevoDestino) {
    seleccion = nuevoDestino;
}

long long valorTotal(const vector<Estante>& estantes) {
    long long valorTotal = 0;
    for (const Estante& estante : estantes) {
        const long long subtotal = estante.valorTotal();
        if (valorTotal > numeric_limits<long long>::max() - subtotal) {
            throw overflow_error("El inventario supera el rango de long long");
        }
        valorTotal += subtotal;
    }
    return valorTotal;
}

int main() {
    // Primero construimos los propietarios: vector -> estantes -> nodos -> productos.
    vector<Estante> estantes;
    estantes.emplace_back("Papeleria");
    estantes.at(0).agregar(Producto("Cuaderno", 300));
    estantes.at(0).agregar(Producto("Lapiz", 100));
    estantes.emplace_back("Libros");
    estantes.at(1).agregar(Producto("Libro", 500));

    // Después prestamos direcciones. Las listas contienen objetos; la vista solo contiene tarjetas.
    vector<const Estante::Nodo*> vista;
    for (const Estante& estante : estantes) {
        const Estante::Nodo* actual = estante.primero();
        while (actual != nullptr) {
            vista.push_back(actual);
            actual = actual->siguienteNodo();
        }
    }

    // Ordenar la vista mueve tarjetas, sin cambiar los enlaces ni mover los productos.
    sort(vista.begin(), vista.end(), [](const Estante::Nodo* izquierdo, const Estante::Nodo* derecho) {
        return izquierdo->consultarProducto().consultarPrecio() < derecho->consultarProducto().consultarPrecio();
    });
    for (const Estante::Nodo* actual : vista) {
        cout << actual->consultarProducto().consultarNombre() << ": "
             << actual->consultarProducto().consultarPrecio() << "\n";
    }

    const Estante::Nodo* seleccion = nullptr;
    seleccionar(seleccion, vista.at(0));
    // La matriz muestra dos productos únicos en tres casillas: seleccion aparece dos veces.
    const Estante::Nodo* const casillas[2][2]{
        {seleccion, nullptr},
        {vista.at(1), seleccion}
    };
    size_t ocupadas = 0;
    for (const auto& fila : casillas) {
        for (const Estante::Nodo* actual : fila) {
            if (actual != nullptr) {
                ++ocupadas;
            }
        }
    }

    // Comprobación del integrador: el inventario y sus enlaces conservaron sus datos y orden.
    const long long antes = valorTotal(estantes);
    if (vista.size() != 3 || antes != 900 || ocupadas != 3 ||
        seleccion->consultarProducto().consultarPrecio() != 100 ||
        estantes.at(0).primero()->consultarProducto().consultarPrecio() != 100 ||
        estantes.at(0).primero()->siguienteNodo()->consultarProducto().consultarPrecio() != 300) {
        cerr << "El integrador produjo un resultado inesperado\n";
        return 1;
    }
    cout << "Inventario en centavos: " << antes << "\n";
    cout << "Casillas ocupadas (pueden repetir producto): " << ocupadas << "\n";

    // Retiramos la selección y la vista. No borran nodos porque no son propietarios.
    seleccion = nullptr;
    vista.clear();
    // Al salir, la matriz se destruye antes que los estantes; ningún observador sobrevive a sus nodos.
}

// Integrador: propietarios, vistas, matrices y ordenamiento
//
// Este ejemplo reúne los nueve pasos en una operación: mostrar productos
// ordenados sin reorganizar su inventario. El vector guarda clases Estante;
// cada clase posee nodos struct que contienen Producto. Construimos una vista
// de const Nodo*, la ordenamos por precio y tomamos direcciones para una matriz.
// Los parámetros const& consultan los propietarios; const Nodo*& cambia una selección.
// Nunca borramos nodos mientras existan vistas en uso. Las casillas repetidas
// no representan existencias adicionales: el total se calcula desde los propietarios.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../02_POO/08_Headers/Producto.cpp -o programa.exe
// Ejecutar: ./programa.exe
//
// Practica: Ordena por nombre y demuestra que la lista original no cambió de orden.

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <stdexcept>
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
    const array<array<const Estante::Nodo*, 2>, 2> casillas{
        array<const Estante::Nodo*, 2>{seleccion, nullptr},
        array<const Estante::Nodo*, 2>{vista.at(1), seleccion}
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

// 6. Nodos dentro de un arreglo, unidos por punteros
//
// Nodo contiene un Producto y una tarjeta hacia otro Nodo. El arreglo guarda
// los nodos completos y administra su vida. Los enlaces solo describen el orden
// de visita: 0 -> 2 -> 1, que puede diferir del orden físico del arreglo.
// El último enlace es nullptr. No uses delete: ningún nodo fue creado con new.
// Copiar este arreglo copia los enlaces tal cual: seguirían apuntando al arreglo
// original. Para una copia independiente habría que reconstruir sus enlaces.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../../02_POO/08_Headers/Producto.cpp -o programa.exe
// Ejecutar: ./programa.exe
//
// Practica: Enlaza 2 -> 0 -> 1 y cambia el inicio. ¿Por qué hay límite de visitas?

#include <array>
#include <iostream>
#include "../../../02_POO/08_Headers/Producto.h"

using namespace std;
using namespace curso;

struct Nodo {
    Producto producto;
    Nodo* siguiente = nullptr;
};

int main() {
    array<Nodo, 3> nodos{
        Nodo{Producto("Cuaderno", 300)},
        Nodo{Producto("Lapiz", 100)},
        Nodo{Producto("Libro", 500)}
    };
    nodos.at(0).siguiente = &nodos.at(2);
    nodos.at(2).siguiente = &nodos.at(1);

    const Nodo* actual = &nodos.at(0);
    size_t visitados = 0;
    // Como hay tres nodos, más de tres visitas implican repetir alguno: un ciclo.
    while (actual != nullptr && visitados < nodos.size()) {
        cout << actual->producto.consultarNombre() << "\n";
        actual = actual->siguiente;
        ++visitados;
    }
    if (actual != nullptr) {
        cerr << "Los enlaces forman un ciclo\n";
        return 1;
    }
}

// 6. Nodos dentro de un arreglo, unidos por punteros
//
// Vamos a guardar nodos completos dentro de un arreglo y unirlos con punteros. Cada Nodo contiene
// un Producto y siguiente, la dirección del próximo nodo. Las cajas están en las posiciones 0, 1 y
// 2, pero podemos recorrerlas en el orden 0, 2 y 1 siguiendo las flechas. El último enlace es
// nullptr. Como las cajas pertenecen al arreglo y no las creamos con new, no usamos delete.
// Limitamos las visitas a tres para detectar si por error cerramos un círculo. Al copiar
// manualmente estas fichas habría que reconstruir sus flechas para no seguir apuntando a las
// originales.
//
// Práctica: Vamos a unir nodos de un arreglo con flechas.
// - Guardemos tres nodos completos y enlacémoslos en otro orden.
// - Recorramos los enlaces hasta nullptr sin usar delete.

#include <iostream>
#include "../../../02_POO/08_Headers/Producto.h"

using namespace std;
using namespace curso;

struct Nodo {
    Producto producto;
    Nodo* siguiente = nullptr;
};

int main() {
    Nodo nodos[3]{
        Nodo{Producto("Cuaderno", 300)},
        Nodo{Producto("Lapiz", 100)},
        Nodo{Producto("Libro", 500)}
    };
    nodos[0].siguiente = &nodos[2];
    nodos[2].siguiente = &nodos[1];

    const Nodo* actual = &nodos[0];
    size_t visitados = 0;
    // Como hay tres nodos, más de tres visitas implican repetir alguno: un ciclo.
    while (actual != nullptr && visitados < 3) {
        cout << actual->producto.consultarNombre() << "\n";
        actual = actual->siguiente;
        ++visitados;
    }
    if (actual != nullptr) {
        cerr << "Los enlaces forman un ciclo\n";
        return 1;
    }
}

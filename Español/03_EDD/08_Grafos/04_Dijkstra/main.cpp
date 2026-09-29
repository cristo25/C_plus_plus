// Dijkstra: caminos de menor costo
//
// Dijkstra obtiene distancias mínimas con pesos no negativos. Usa una cola de prioridad de menor
// costo, mejora distancias y descarta entradas obsoletas. INFINITO indica un vértice
// inalcanzable. Esta versión permite entradas repetidas en la cola: tiempo O((V + E) log(E + 2))
// y memoria O(V + E). No devuelve las rutas, solo sus costos.
//
// Analogía: Un repartidor compara el costo total de las rutas y siempre considera primero la
// alternativa más barata disponible.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Agrega un vector de predecesores para reconstruir una ruta. Para pesos negativos
// investiga Bellman-Ford en una ampliación posterior.

#include "../Grafo.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    Grafo mapa(5);
    mapa.conectar(0, 1, 4);
    mapa.conectar(0, 2, 1);
    mapa.conectar(2, 1, 2);
    mapa.conectar(1, 3, 1);
    mapa.conectar(2, 3, 7);
    // La cola considera el menor costo conocido; INFINITO marca los destinos que no se alcanzan.
    const auto distancias = dijkstra(mapa, 0);

    for (size_t i = 0; i < distancias.size(); ++i) {
        cout << i << ": ";
        if (distancias.at(i) == INFINITO) {
            cout << "sin ruta\n";
        } else {
            cout << distancias.at(i) << "\n";
        }
    }
}

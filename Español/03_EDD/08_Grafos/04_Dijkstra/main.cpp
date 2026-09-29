// Dijkstra: caminos de menor costo
//
// Dijkstra obtiene distancias mínimas con pesos no negativos. Usa una cola de prioridad de menor
// costo, mejora distancias y descarta entradas obsoletas. INFINITO indica un vértice inalcanzable.
// Además de revisar conexiones, esta versión organiza los candidatos en una cola de prioridad para
// elegir el de menor costo. Al haber más candidatos, mantener esa prioridad requiere más ajustes.
// Un mismo punto puede aparecer varias veces si encontramos mejores caminos hacia él; por eso la
// cola también necesita espacio para esos registros pendientes. La memoria puede crecer con los
// vértices y las aristas del grafo (O(V + E), donde V cuenta puntos y E cuenta conexiones). La
// función dijkstra devuelve los costos; caminosMinimos también conserva desde qué punto llegamos a
// cada destino, para reconstruir las rutas.
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

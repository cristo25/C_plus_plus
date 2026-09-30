// Grafos
//
// Vamos a usar un mismo mapa para contestar preguntas distintas. Con BFS exploramos por capas; con
// DFS seguimos una rama antes de volver; con Dijkstra buscamos el menor costo acumulado.
// Compartimos Grafo.h para no construir un mapa diferente en cada prueba. Podemos comparar los
// recorridos, pero no interpretamos el orden de BFS o DFS como una lista de costos: cada
// herramienta responde una pregunta diferente.
//
// Práctica: Vamos a estudiar un mapa con varias preguntas.
// - Conectemos lugares con costos no negativos.
// - Comparemos BFS, DFS y el camino de menor costo desde un origen.

#include "Grafo.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    Grafo mapa(4);
    // Cada conexión es dirigida. Los recorridos comparan el orden; Dijkstra compara los costos.
    mapa.conectar(0, 1, 4);
    mapa.conectar(0, 2, 1);
    mapa.conectar(2, 1, 2);
    mapa.conectar(1, 3, 1);
    mapa.conectar(2, 3, 7);
    if (!((bfs(mapa, 0) == vector<size_t>{0, 1, 2, 3}))) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    if (!((dfs(mapa, 0) == vector<size_t>{0, 1, 3, 2}))) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    if (!(dijkstra(mapa, 0).at(3) == 4)) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    cout << "BFS: ";
    for (auto vertice : bfs(mapa, 0)) {
        cout << vertice << ' ';
    }
    cout << "\nDFS: ";
    for (auto vertice : dfs(mapa, 0)) {
        cout << vertice << ' ';
    }
    cout << "\nCosto minimo 0 -> 3: " << dijkstra(mapa, 0).at(3) << "\n";
}

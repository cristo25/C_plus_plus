#include "Grafo.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    Grafo mapa(4);
    mapa.conectar(0, 1, 4);
    mapa.conectar(0, 2, 1);
    mapa.conectar(2, 1, 2);
    mapa.conectar(1, 3, 1);
    mapa.conectar(2, 3, 7);
    assert((bfs(mapa, 0) == vector<size_t>{0, 1, 2, 3}));
    assert((dfs(mapa, 0) == vector<size_t>{0, 1, 3, 2}));
    assert(dijkstra(mapa, 0).at(3) == 4);
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

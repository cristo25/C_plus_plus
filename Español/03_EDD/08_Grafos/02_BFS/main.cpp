// BFS: búsqueda en anchura
//
// Vamos a explorar un mapa por capas. Primero visitamos el inicio, después sus vecinos y después
// los vecinos de estos. Guardamos lo pendiente en una cola para respetar ese orden. A este
// recorrido lo llamamos BFS, o búsqueda en anchura. Marcamos cada lugar al agregarlo para no
// repetirlo, aunque haya caminos de regreso. Solo llegamos a lugares conectados con el inicio. Si
// recorremos todo el mapa, revisamos sus lugares y caminos (O(V + E), con V lugares y E
// conexiones).
//

#include "../Grafo.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;
using namespace curso;

int main() {
    Grafo grafo(5);
    grafo.conectar(0, 1);
    grafo.conectar(0, 2);
    grafo.conectar(1, 3);
    grafo.conectar(2, 3);
    grafo.conectar(3, 0);
    // BFS visita por capas con una cola. El vértice 4 queda fuera porque no hay ruta hasta él.
    const auto orden = bfs(grafo, 0);

    for (auto vertice : orden) {
        cout << vertice << ' ';
    }
    cout << "\n";
}

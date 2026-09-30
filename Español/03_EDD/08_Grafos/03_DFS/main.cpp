// DFS: búsqueda en profundidad
//
// Vamos a seguir un camino hasta donde podamos y después regresar para probar otro. Podemos
// imaginar la exploración de un laberinto. A este recorrido lo llamamos DFS, o búsqueda en
// profundidad. Aquí usamos recursión para recordar por dónde volver. Marcamos los lugares
// visitados para no dar vueltas sin fin. El orden puede diferir del de BFS aunque ambos alcancen
// los mismos lugares. Si revisamos todo el mapa, visitamos sus lugares y caminos.
//
// Práctica: Vamos a explorar un mapa por caminos completos.
// - Partamos de un lugar y recorramos sus conexiones con DFS.
// - Marquemos los lugares visitados para evitar vueltas sin fin.

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
    // DFS sigue una rama antes de volver; los visitados evitan repetir el ciclo 3 -> 0.
    const auto orden = dfs(grafo, 0);

    for (auto vertice : orden) {
        cout << vertice << ' ';
    }
    cout << "\n";
}

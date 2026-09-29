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

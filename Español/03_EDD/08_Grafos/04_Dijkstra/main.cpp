// Dijkstra: caminos de menor costo
//
// Vamos a buscar el camino cuyo costo total sea menor. Podemos imaginar que cada carretera indica
// minutos: llegar con menos carreteras no siempre significa llegar antes. Con Dijkstra guardamos el
// mejor costo conocido y atendemos primero el candidato más barato mediante una cola de prioridad.
// Si encontramos una mejora, actualizamos el costo. Esta versión requiere costos no negativos.
// INFINITO es una marca para indicar que aún no encontramos una ruta; no representa minutos reales.
// dijkstra devuelve costos; en caminosMinimos también guardamos de dónde llegamos para reconstruir
// una ruta.
//

#include "../Grafo.h"
#include <iostream>
// Guardamos una colección que puede crecer con vector.
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

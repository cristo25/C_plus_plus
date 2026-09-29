#include "../Grafo.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    Grafo mapa(3);
    mapa.conectar(0, 1, 5);
    mapa.conectar(1, 0, 5); // Carretera de ida y vuelta.
    mapa.conectar(1, 2, 2); // Solo ida.

    for (const auto& arista : mapa.vecinos(1)) {
        cout << "1 -> " << arista.destino << " costo " << arista.peso << "\n";
    }
}

// Representar grafos
//
// Vamos a dibujar lugares unidos por caminos. A cada lugar lo llamamos vértice y a cada conexión
// arista; al conjunto lo llamamos grafo. En conectar indicamos origen, destino y costo. Si
// queremos ida y vuelta agregamos ambas direcciones. Guardamos una lista de vecinos por lugar: la
// memoria crece con los lugares y caminos. Otra posibilidad es una tabla con una casilla por
// pareja de lugares: cinco lugares necesitan 25 casillas y diez necesitan 100.
//
// Práctica: Vamos a representar lugares y caminos.
// - Creemos al menos cuatro lugares y conectemos algunos de ellos.
// - Mostremos los vecinos de cada lugar y señalemos un lugar aislado.

#include "../Grafo.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    Grafo mapa(3);
    // Una arista representa un trayecto de origen a destino; el tercer argumento es su costo.
    mapa.conectar(0, 1, 5);
    mapa.conectar(1, 0, 5); // Carretera de ida y vuelta.
    mapa.conectar(1, 2, 2); // Solo ida.

    for (const auto& arista : mapa.vecinos(1)) {
        cout << "1 -> " << arista.destino << " costo " << arista.peso << "\n";
    }
}

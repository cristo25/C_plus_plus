// Representar grafos
//
// Un grafo representa puntos conectados: los puntos se llaman vértices y las conexiones, aristas.
// Imagina edificios unidos por caminos. Una lista de adyacencia guarda una lista por edificio y una
// entrada por conexión registrada. La memoria crece con la cantidad de edificios y conexiones
// (O(V + E): V es la cantidad de vértices y E la de aristas). Una matriz de adyacencia reserva una
// casilla para cada pareja de edificios, aunque no estén conectados: con 5 edificios tiene 5 por 5,
// es decir, 25 casillas; con 10 tiene 100 (O(V²): V² significa V multiplicado por V). Estas
// expresiones describen cómo crece la memoria, no una cantidad exacta de bytes. Grafo representa
// aristas dirigidas con pesos no negativos. Para una conexión no dirigida agrega ambas direcciones.
//
// Analogía: Las ciudades son vértices; las carreteras son aristas; el costo de recorrer una
// carretera es su peso.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Dibuja el mapa y agrega un vértice aislado. Compara listas y matrices en un grafo
// con pocas aristas.

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

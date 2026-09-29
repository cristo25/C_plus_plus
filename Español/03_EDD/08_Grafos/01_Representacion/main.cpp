// Representar grafos
//
// Un grafo contiene vértices y aristas. La lista de adyacencia guarda los vecinos de cada
// vértice y ocupa O(V + E); una matriz de adyacencia ocupa O(V²). Grafo representa aristas
// dirigidas con pesos no negativos. Para una conexión no dirigida agrega ambas direcciones.
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

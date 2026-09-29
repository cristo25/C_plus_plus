// BFS: búsqueda en anchura
//
// BFS usa una cola y visita por niveles. Marca cada vértice al encolarlo para no repetirlo cuando
// hay ciclos. Recorre solo los vértices alcanzables desde el inicio. En grafos sin pesos, los
// niveles describen distancias mínimas en número de aristas. Al recorrer las listas de vecinos,
// visitamos los puntos alcanzables y revisamos sus conexiones. En el peor caso el trabajo crece con
// todos los puntos y conexiones del grafo (O(V + E), donde V cuenta vértices y E cuenta aristas).
// Las marcas de visitado y los puntos pendientes de procesar necesitan espacio que crece con la
// cantidad de puntos (O(V) de memoria adicional).
//
// Analogía: Exploras una ciudad por anillos: primero los vecinos cercanos, después sus vecinos.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Agrega una arista hacia 4. Explica cómo cambiaría el orden al cambiar el orden de
// los vecinos.

#include "../Grafo.h"
#include <iostream>
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

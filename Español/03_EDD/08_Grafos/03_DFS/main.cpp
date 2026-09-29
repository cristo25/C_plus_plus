// DFS: búsqueda en profundidad
//
// DFS sigue una rama hasta que no puede avanzar y luego regresa. Puede usar recursión o una pila
// explícita. Los visitados evitan ciclos. Al recorrer las listas de vecinos, visitamos los puntos
// alcanzables y revisamos sus conexiones. En el peor caso el trabajo crece con todos los puntos y
// conexiones del grafo (O(V + E), donde V cuenta vértices y E cuenta aristas). Las marcas de
// visitado y los puntos pendientes de procesar necesitan espacio que crece con la cantidad de
// puntos (O(V) de memoria adicional). El orden depende del orden de los vecinos.
//
// Analogía: Exploras un laberinto siguiendo un pasillo hasta el fondo y retrocedes para probar
// los demás.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Compara este recorrido con BFS usando el mismo dibujo.

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
    // DFS sigue una rama antes de volver; los visitados evitan repetir el ciclo 3 -> 0.
    const auto orden = dfs(grafo, 0);

    for (auto vertice : orden) {
        cout << vertice << ' ';
    }
    cout << "\n";
}

// Integrador: procesar tareas y consultar rutas
//
// Combina vector, lista, pila, cola, cola de prioridad, ABB, tabla hash, grafo, ordenamiento y
// búsqueda. Reutiliza los headers de EDD. La cola define el orden de trabajo; la lista conserva
// el historial y la pila permite consultar qué se desharía primero.
//
// Analogía: Un taller recibe órdenes, las atiende, conserva un historial, organiza prioridades y
// consulta un mapa para las entregas.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Agrega una cuarta tarea y actualiza las comprobaciones. Explica qué estructura
// elegirías si solo necesitaras guardar el historial; este programa reúne varias para practicar,
// no porque todas sean necesarias para ese requisito.

#include "../03_Listas_Ligadas/01_Simplemente_Ligada/ListaSimple.h"
#include "../06_Arboles/Arbol.h"
#include "../08_Grafos/Grafo.h"
#include "../09_Ordenamiento/Ordenamientos.h"
#include "../10_Busqueda/Busquedas.h"
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> ids{3, 1, 2};
    unordered_map<int, string> nombres{{1, "Leer"}, {2, "Compilar"}, {3, "Practicar"}};
    // La cola organiza el trabajo por llegada; la tabla hash relaciona cada ID con su nombre.
    queue<int> pendientes;
    priority_queue<int> urgencias;
    for (int id : ids) {
        pendientes.push(id);
        urgencias.push(id);
    }
    ListaSimple historial;
    // La pila consulta la última tarea; la lista registra el historial y el ABB facilita
    // consultas.
    stack<int> deshacer;
    Arbol indice;
    while (!pendientes.empty()) {
        int id = pendientes.front();
        pendientes.pop();
        historial.agregar(id);
        deshacer.push(id);
        indice.insertar(id);
        cout << "Procesar: " << nombres.at(id) << "\n";
    }
    // assert comprueba un resultado del integrador; no realiza operaciones del programa.
    assert(historial.valores() == ids && deshacer.top() == 2);
    assert(urgencias.top() == 3 && indice.contiene(2));
    mergeSort(ids);
    assert(ids == indice.valores());
    assert(binaria(ids, 2).value() == 1);

    // El grafo modela trayectos; Dijkstra calcula el costo de entrega más bajo.
    Grafo rutas(3);
    rutas.conectar(0, 1, 4);
    rutas.conectar(0, 2, 1);
    rutas.conectar(2, 1, 1);
    assert(bfs(rutas, 0).size() == 3 && dfs(rutas, 0).size() == 3);
    assert(dijkstra(rutas, 0).at(1) == 2);
    cout << "Ultima tarea (deshacer): " << nombres.at(deshacer.top()) << "\n";
    cout << "Costo minimo de entrega 0 -> 1: " << dijkstra(rutas, 0).at(1) << "\n";
}

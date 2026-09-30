// Integrador: procesar tareas y consultar rutas
//
// Vamos a reunir las estructuras en un taller de tareas y entregas. Guardamos tareas en un vector,
// atendemos por una cola y anotamos lo ocurrido en una lista. Con una pila consultamos cuál sería
// la última acción a deshacer. Usamos un árbol y una tabla por id para practicar consultas;
// ordenamos números antes de buscarlos por mitades. Finalmente usamos un grafo para calcular rutas.
// Cada estructura responde una necesidad distinta; este ejemplo las reúne para observar cómo se
// pasan los datos.
//
// Práctica: Vamos a organizar tareas y rutas en un taller.
// - Guardemos tareas y atendámoslas en orden de llegada.
// - Consultemos una tarea por id y calculemos una ruta entre lugares.

#include "../03_Listas_Ligadas/01_Simplemente_Ligada/ListaSimple.h"
#include "../06_Arboles/Arbol.h"
#include "../08_Grafos/Grafo.h"
#include "../09_Ordenamiento/Ordenamientos.h"
#include "../10_Busqueda/Busquedas.h"
#include <iostream>
// Atendemos por llegada con queue o por importancia con priority_queue.
#include <queue>
// Guardamos una pila: con stack sale primero lo último que entró.
#include <stack>
// Guardamos y trabajamos con texto mediante string.
#include <string>
// Relacionamos una clave con un dato para buscar, como matrícula y nombre.
#include <unordered_map>
// Guardamos una colección que puede crecer con vector.
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
    if (!(historial.valores() == ids && deshacer.top() == 2)) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    if (!(urgencias.top() == 3 && indice.contiene(2))) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    mergeSort(ids);
    if (!(ids == indice.valores())) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    if (!(binaria(ids, 2).value() == 1)) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }

    // El grafo modela trayectos; Dijkstra calcula el costo de entrega más bajo.
    Grafo rutas(3);
    rutas.conectar(0, 1, 4);
    rutas.conectar(0, 2, 1);
    rutas.conectar(2, 1, 1);
    if (!(bfs(rutas, 0).size() == 3 && dfs(rutas, 0).size() == 3)) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    if (!(dijkstra(rutas, 0).at(1) == 2)) {
        cerr << "La comprobacion no dio el resultado esperado.\n";
        return 1;
    }
    cout << "Ultima tarea (deshacer): " << nombres.at(deshacer.top()) << "\n";
    cout << "Costo minimo de entrega 0 -> 1: " << dijkstra(rutas, 0).at(1) << "\n";
}

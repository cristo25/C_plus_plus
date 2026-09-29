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
    const auto orden = dfs(grafo, 0);

    for (auto vertice : orden) {
        cout << vertice << ' ';
    }
    cout << "\n";
}

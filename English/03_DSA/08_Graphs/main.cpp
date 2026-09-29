// Graphs
//
// Study representation, traversal and minimum costs. BFS and DFS ignore weights; Dijkstra uses
// them. The integration example compares traversals and obtains minimum cost 4 from 0 to 3. Free
// functions in these headers are inline to avoid multiple definitions when linking.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe

#include "Graph.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    Graph map(4);
    // Each connection is directed. Traversals compare visit order; Dijkstra compares costs.
    map.connect(0, 1, 4);
    map.connect(0, 2, 1);
    map.connect(2, 1, 2);
    map.connect(1, 3, 1);
    map.connect(2, 3, 7);
    // assert checks an integration result; it does not perform application operations.
    assert((bfs(map, 0) == vector<size_t>{0, 1, 2, 3}));
    assert((dfs(map, 0) == vector<size_t>{0, 1, 3, 2}));
    assert(dijkstra(map, 0).at(3) == 4);
    cout << "BFS: ";
    for (auto vertex : bfs(map, 0)) {
        cout << vertex << ' ';
    }
    cout << "\nDFS: ";
    for (auto vertex : dfs(map, 0)) {
        cout << vertex << ' ';
    }
    cout << "\nMinimum cost 0 -> 3: " << dijkstra(map, 0).at(3) << "\n";
}

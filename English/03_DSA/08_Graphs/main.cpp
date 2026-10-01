// Graphs
//
// We will use one map to answer different questions. With BFS we explore in layers; with DFS we
// follow a branch before returning; with Dijkstra we find the lowest total cost. We share Graph.h
// so every test uses the same map. We can compare traversal orders, but we do not treat BFS or DFS
// order as a list of costs: each tool answers a different question.
//
// Practice: We will study a map with several questions.
// - We will connect places with nonnegative costs.
// - We will compare BFS, DFS and the lowest-cost path from one starting place.

#include "Graph.h"
#include <iostream>
// We store a collection that can grow using vector.
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
    if (!((bfs(map, 0) == vector<size_t>{0, 1, 2, 3}))) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    if (!((dfs(map, 0) == vector<size_t>{0, 1, 3, 2}))) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    if (!(dijkstra(map, 0)[3] == 4)) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    cout << "BFS: ";
    for (auto vertex : bfs(map, 0)) {
        cout << vertex << ' ';
    }
    cout << "\nDFS: ";
    for (auto vertex : dfs(map, 0)) {
        cout << vertex << ' ';
    }
    cout << "\nMinimum cost 0 -> 3: " << dijkstra(map, 0)[3] << "\n";
}

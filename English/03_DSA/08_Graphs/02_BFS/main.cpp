// BFS: breadth-first search
//
// We will explore a map in layers. We visit the start, then its neighbors, then their neighbors.
// We keep pending places in a queue to preserve that order. We call this BFS, or breadth-first
// search. We mark each place when adding it so we do not repeat it, even with roads back. We
// reach only places connected to the start. A full traversal checks the places and roads.
//
// Practice: We will explore a map layer by layer.
// - We will start at one place and traverse its neighbors with BFS.
// - We will avoid visiting the same place twice.

#include "../Graph.h"
#include <iostream>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace course;

int main() {
    Graph graph(5);
    graph.connect(0, 1);
    graph.connect(0, 2);
    graph.connect(1, 3);
    graph.connect(2, 3);
    graph.connect(3, 0);
    // BFS visits in layers using a queue. Vertex 4 stays out because no path reaches it.
    const auto order = bfs(graph, 0);

    for (auto vertex : order) {
        cout << vertex << ' ';
    }
    cout << "\n";
}

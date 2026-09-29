// BFS: breadth-first search
//
// BFS uses a queue and visits by levels. Mark vertices when enqueueing to prevent repeated visits
// through cycles. Only vertices reachable from the start are visited. In unweighted graphs, levels
// express minimum edge counts. Traversing neighbor lists visits reachable points and inspects their
// connections. In the worst case, work grows with all graph points and connections (O(V + E), where
// V counts vertices and E counts edges). Visited markers and points waiting to be processed need
// space that grows with the point count (O(V) additional memory).
//
// Analogy: Explore a city in rings, starting with nearby neighbors and then their neighbors.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Connect a vertex to 4 and explain how neighbor ordering affects the traversal order.

#include "../Graph.h"
#include <iostream>
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

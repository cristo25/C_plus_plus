// DFS: depth-first search
//
// DFS follows a branch as far as possible, then backtracks. Use recursion or an explicit stack.
// Visited markers prevent cycles. Traversing neighbor lists visits reachable points and inspects
// their connections. In the worst case, work grows with all graph points and connections (O(V + E),
// where V counts vertices and E counts edges). Visited markers and points waiting to be processed
// need space that grows with the point count (O(V) additional memory). Order depends on neighbor
// order; use an explicit stack for great depths.
//
// Analogy: Explore a maze by following a hallway to its end, then returning to try the remaining
// hallways.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Compare this traversal with BFS on the same drawing.

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
    // DFS follows a branch before returning; visited flags avoid repeating the 3 -> 0 cycle.
    const auto order = dfs(graph, 0);

    for (auto vertex : order) {
        cout << vertex << ' ';
    }
    cout << "\n";
}

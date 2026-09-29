// DFS: depth-first search
//
// We will follow a path as far as possible and then return to try another. We can picture exploring
// a maze. We call this DFS, or depth-first search. Here we use recursion to remember where to
// return. We mark visited places so we do not go around forever. The order can differ from BFS even
// though both reach the same places. A full traversal grows with the map’s V places and E roads
// (O(V + E)).
//

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
    // DFS follows a branch before returning; visited flags avoid repeating the 3 -> 0 cycle.
    const auto order = dfs(graph, 0);

    for (auto vertex : order) {
        cout << vertex << ' ';
    }
    cout << "\n";
}

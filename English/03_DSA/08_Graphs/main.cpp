#include "Graph.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    Graph map(4);
    map.connect(0, 1, 4);
    map.connect(0, 2, 1);
    map.connect(2, 1, 2);
    map.connect(1, 3, 1);
    map.connect(2, 3, 7);
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

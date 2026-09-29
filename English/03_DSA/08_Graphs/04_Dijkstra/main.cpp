// Dijkstra: minimum-cost paths
//
// Dijkstra finds minimum distances for nonnegative weights. Use a minimum-priority queue,
// improve distances and discard outdated entries. INFINITY_DISTANCE means unreachable. Repeated
// queue entries give this implementation O((V + E) log(E + 2)) time and O(V + E) space. It
// returns costs, not routes.
//
// Analogy: A courier compares total route costs and always considers the cheapest available
// alternative first.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Track predecessors to reconstruct a route. For negative weights, study Bellman-Ford
// in a later extension.

#include "../Graph.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    Graph map(5);
    map.connect(0, 1, 4);
    map.connect(0, 2, 1);
    map.connect(2, 1, 2);
    map.connect(1, 3, 1);
    map.connect(2, 3, 7);
    // The queue considers the smallest known cost; the infinity sentinel marks unreachable
    // vertices.
    const auto distances = dijkstra(map, 0);

    for (size_t i = 0; i < distances.size(); ++i) {
        cout << i << ": ";
        if (distances.at(i) == INFINITY_DISTANCE) {
            cout << "unreachable\n";
        } else {
            cout << distances.at(i) << "\n";
        }
    }
}

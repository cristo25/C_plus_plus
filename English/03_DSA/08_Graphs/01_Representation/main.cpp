// Representing graphs
//
// We will draw places joined by roads. We call each place a vertex, each connection an edge, and
// the whole arrangement a graph. In connect we give the source, destination and cost. For travel
// both ways we add both directions. We keep a neighbor list per place: memory grows with places
// and roads. Another option is a table with one slot per pair of places: five places need 25
// slots and ten need 100.
//
// Practice: We will represent places and roads.
// - We will create at least four places and connect some of them.
// - We will show each place's neighbors and identify an isolated place.

#include "../Graph.h"
#include <iostream>

using namespace std;
using namespace course;

int main() {
    Graph map(3);
    // An edge is a trip from source to destination; the third argument is its cost.
    map.connect(0, 1, 5);
    map.connect(1, 0, 5); // Two-way road.
    map.connect(1, 2, 2); // One-way road.

    for (const auto& edge : map.neighbors(1)) {
        cout << "1 -> " << edge.destination << " cost " << edge.weight << "\n";
    }
}

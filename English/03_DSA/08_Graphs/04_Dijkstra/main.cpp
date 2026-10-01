// Dijkstra: minimum-cost paths
//
// We will look for the path with the lowest total cost. We can picture roads labeled in minutes:
// fewer roads do not always mean earlier arrival. With Dijkstra we keep the best known cost and use
// a priority queue to process the cheapest candidate first. When we find an improvement, we update
// its cost. This version requires nonnegative costs. INFINITY_DISTANCE is a marker for a route not
// yet found, not a real number of minutes. dijkstra returns costs; shortestPaths also remembers
// where we came from so a route can be rebuilt.
//
// Practice: We will find a lowest-cost route.
// - We will assign nonnegative costs to roads between places.
// - We will show the cost of reaching each place from a chosen start.

#include "../Graph.h"
#include <iostream>
// We store a collection that can grow using vector.
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
        if (distances[i] == INFINITY_DISTANCE) {
            cout << "unreachable\n";
        } else {
            cout << distances[i] << "\n";
        }
    }
}

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

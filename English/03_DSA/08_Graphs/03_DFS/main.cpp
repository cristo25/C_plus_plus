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
    const auto order = dfs(graph, 0);

    for (auto vertex : order) {
        cout << vertex << ' ';
    }
    cout << "\n";
}

// Representing graphs
//
// A graph represents connected points: points are called vertices and connections are edges.
// Imagine buildings joined by roads. An adjacency list stores a list for each building and an entry
// for each recorded connection. Memory grows with both the buildings and connections (O(V + E): V
// is the vertex count and E is the edge count). An adjacency matrix reserves a slot for every pair
// of buildings, even when they are unconnected: 5 buildings need 5 times 5, or 25 slots; 10 need
// 100 (O(V²): V² means V multiplied by V). These expressions describe memory growth, not an exact
// byte count. Graph stores directed edges with nonnegative weights. Add both directions for an
// undirected connection.
//
// Analogy: Cities are vertices, roads are edges, and the cost of traveling a road is its weight.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Draw the map and add an isolated vertex. Compare lists and matrices for a sparse
// graph.

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

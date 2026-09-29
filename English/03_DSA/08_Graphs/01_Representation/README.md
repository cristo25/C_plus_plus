# Representing graphs

## What you will learn

A graph has vertices and edges. An adjacency list stores neighbors using O(V + E) space; an adjacency matrix uses O(V²). `Graph` stores directed edges with nonnegative weights. Add both directions for an undirected connection.

## Analogy

Cities are vertices, roads are edges, and the cost of traveling a road is its weight.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `1 -> 0 cost 5` and `1 -> 2 cost 2`.

## Practice

Draw the map and add an isolated vertex. Compare lists and matrices for a sparse graph.

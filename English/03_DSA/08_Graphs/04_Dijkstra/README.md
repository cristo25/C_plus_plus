# Dijkstra: minimum-cost paths

## What you will learn

Dijkstra finds minimum distances for nonnegative weights. Use a minimum-priority queue, improve distances and discard outdated entries. `INFINITY_DISTANCE` means unreachable. Repeated queue entries give this implementation O((V + E) log(E + 2)) time and O(V + E) space. It returns costs, not routes.

## Analogy

A courier compares total route costs and always considers the cheapest available alternative first.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: costs `0, 3, 1, 4` for vertices 0 through 3; vertex 4 shows `unreachable`.

## Practice

Track predecessors to reconstruct a route. For negative weights, study Bellman-Ford in a later extension.

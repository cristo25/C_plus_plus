# BFS: breadth-first search

## What you will learn

BFS uses a queue and visits by levels. Mark vertices when enqueueing to prevent repeated visits through cycles. Only vertices reachable from the start are visited. In unweighted graphs, levels express minimum edge counts. Time O(V + E), auxiliary memory O(V).

## Analogy

Explore a city in rings, starting with nearby neighbors and then their neighbors.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `0 1 2 3`. Isolated vertex 4 is absent.

## Practice

Connect a vertex to 4 and explain how neighbor ordering affects the traversal order.

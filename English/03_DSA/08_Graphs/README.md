# Graphs

We will connect this topic’s pieces before solving its integration task. Each link contains the program, comments and a practice task with requirements.

## Representing graphs

We will draw places joined by roads. We call each place a vertex, each connection an edge, and the whole arrangement a graph. In connect we give the source, destination and cost. For travel both ways we add both directions. We keep a neighbor list per place: memory grows with places and roads. Another option is a table with one slot per pair of places: five places need 25 slots and ten need 100.

[Commented program](01_Representation/main.cpp).

## BFS: breadth-first search

We will explore a map in layers. We visit the start, then its neighbors, then their neighbors. We keep pending places in a queue to preserve that order. We call this BFS, or breadth-first search. We mark each place when adding it so we do not repeat it, even with roads back. We reach only places connected to the start. A full traversal checks the places and roads.

[Commented program](02_BFS/main.cpp).

## DFS: depth-first search

We will follow a path as far as possible and then return to try another. We can picture exploring a maze. We call this DFS, or depth-first search. Here we use recursion to remember where to return. We mark visited places so we do not go around forever. The order can differ from BFS even though both reach the same places. To visit the whole map, we check its places and roads.

[Commented program](03_DFS/main.cpp).

## Dijkstra: minimum-cost paths

We will look for the path with the lowest total cost. We can picture roads labeled in minutes: fewer roads do not always mean earlier arrival. With Dijkstra we keep the best known cost and use a priority queue to process the cheapest candidate first. When we find an improvement, we update its cost. This version requires nonnegative costs. INFINITY_DISTANCE is a marker for a route not yet found, not a real number of minutes. dijkstra returns costs; shortestPaths also remembers where we came from so a route can be rebuilt.

[Commented program](04_Dijkstra/main.cpp).

## Graphs

We will use one map to answer different questions. With BFS we explore in layers; with DFS we follow a branch before returning; with Dijkstra we find the lowest total cost. We share Graph.h so every test uses the same map. We can compare traversal orders, but we do not treat BFS or DFS order as a list of costs: each tool answers a different question.

[Commented program](main.cpp).

**Practice.** We will write an integrated school-route program.

- We will store at least five buildings and travel minutes between them.
- We will display BFS and DFS from the same building.
- We will calculate lowest costs with Dijkstra.
- We will include a disconnected building and report when it is unreachable.
- We will keep the graph and its operations in a header.

[Back to the general guide](../../README.md).

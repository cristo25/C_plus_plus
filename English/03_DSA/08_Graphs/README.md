# Graphs

Study representation, traversal and minimum costs. BFS and DFS ignore weights; Dijkstra uses them. The integration example compares traversals and obtains minimum cost 4 from 0 to 3. Free functions in these headers are inline to avoid multiple definitions when linking.

## Study order

1. [Representing graphs](01_Representation/main.cpp)
2. [BFS: breadth-first search](02_BFS/main.cpp)
3. [DFS: depth-first search](03_DFS/main.cpp)
4. [Dijkstra: minimum-cost paths](04_Dijkstra/main.cpp)

After finishing the subfolders, read and run the `main.cpp` **in this folder**. It combines what you learned in the individual lessons.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Every subfolder has its own program. Compile one example at a time: each has its own `main` function.

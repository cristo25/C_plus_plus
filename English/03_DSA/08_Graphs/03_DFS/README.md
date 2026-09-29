# DFS: depth-first search

## What you will learn

DFS follows a branch as far as possible, then backtracks. Use recursion or an explicit stack. Visited markers prevent cycles. Time O(V + E), auxiliary memory O(V). Order depends on neighbor order; use an explicit stack for great depths.

## Analogy

Explore a maze by following a hallway to its end, then returning to try the remaining hallways.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `0 1 3 2`. The cycle back to 0 does not cause infinite recursion.

## Practice

Compare this traversal with BFS on the same drawing.

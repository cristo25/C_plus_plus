# Sorting with the standard library

## What you will learn

`sort` provides O(n log n) worst-case comparisons without stability guarantees. `stable_sort` preserves equivalent elements' order. The comparator must express a strict order: use `<`, not `<=`. A lambda `[](...) { ... }` defines a small function at its use site.

## Analogy

Give the drawer to a tested sorting tool and tell it how to compare its objects.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Ana: 8`, `Luis: 8` and `Eva: 9`. The tied grades preserve their original order.

## Practice

Sort by name, then by descending grade while preserving ties.

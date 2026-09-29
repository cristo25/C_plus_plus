# Quick sort

## What you will learn

Choose a pivot, partition values and recursively sort the partitions. Usually O(n log n), but this last-element pivot can take O(n²) for sorted or equal inputs. The recursive stack can reach O(n). Not stable. Read `quickSort` in `../Sorts.h`.

## Analogy

A pivot splits a line: smaller values move left and the rest move right; repeat within each group.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `-1 0 3 3 5`.

## Practice

Trace pivots for 4, 1, 3, 2. Try sorted data and explain why this version becomes unbalanced.

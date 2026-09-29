# Circular linked list

## What you will learn

The last node points to the first. Stop on returning to the start; waiting for `nullptr` would loop forever. Append costs O(1), while searching and removing by value cost O(n). This variant is singly linked and circular.

## Analogy

A wheel of turns returns to the first person after serving the last.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `1 3`. Traversal makes one complete lap.

## Practice

Draw a single-node ring, which points to itself. Explain why removing it needs a special case.

# Binary trees: roots, children and leaves

## What you will learn

A tree connects nodes without cycles. The root has no parent; leaves have no children. A binary tree allows at most two children per node. A binary tree need not order its values.

## Analogy

An organization chart starts with one manager and branches into subordinates, at most two per manager here.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Nodes: 3`. The `unique_ptr` members release children together with their root.

## Practice

Draw the tree, identify its leaves and add a grandchild.

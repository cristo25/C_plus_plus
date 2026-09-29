# Binary search trees (BST)

## What you will learn

This BST places smaller values on the left and larger ones on the right, rejecting duplicates. Insertion, search and removal cost O(h), where h is height. Removing a node with two children replaces it with the smallest value in its right subtree. An unbalanced BST may become a chain.

## Analogy

Each node in a number guide tells you whether to follow smaller or larger values.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `1 3 6 10`.

## Practice

Insert already sorted numbers and draw the tree. Compare its height with another insertion order.

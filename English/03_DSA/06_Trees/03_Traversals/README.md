# Tree traversals

## What you will learn

Preorder visits root, left, right. Inorder visits left, root, right. Postorder visits left, right, root. Inorder produces sorted values in a BST. Traversals take O(n), with an O(h) recursive stack plus the output vector.

## Analogy

Visit a house and record each room before its annexes, between its annexes, or after them.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output, in order: preorder `4 2 1 3 6 5 7`, inorder `1 2 3 4 5 6 7`, and postorder `1 3 2 5 7 6 4`.

## Practice

Draw the tree and reproduce each traversal with arrows before running it.

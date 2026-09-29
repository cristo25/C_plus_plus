# Doubly linked list

## What you will learn

Each node knows its previous and next node. Keeping a head and tail permits O(1) append and traversal in either direction. Searching still costs O(n); unlinking an already located node updates both links.

## Analogy

Train cars have couplings at both ends, allowing travel in either direction.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `30 20 10`.

## Practice

Draw the two links changed when removing a middle node.

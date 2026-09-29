# The stack adapter

## What you will learn

`stack` exposes only stack operations: `push`, `top`, `pop`, `size` and `empty`. `pop` removes without returning a value; query `top` first. An adapter restricts operations on its underlying container.

## Analogy

A box of plates with one opening at the top cannot expose the middle plate.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Undo: Delete`.

## Practice

Simulate two actions and two undo operations, and protect a third undo attempt.

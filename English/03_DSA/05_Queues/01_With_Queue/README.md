# FIFO queue

## What you will learn

`queue` processes values in arrival order: first in, first out. Add with `push`, inspect with `front` and remove with `pop`. Check `empty` before access.

## Analogy

A line at a food stall serves the first arrival first.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Serve: Ana`, then `Serve: Luis`.

## Practice

Add a third person and verify the order.

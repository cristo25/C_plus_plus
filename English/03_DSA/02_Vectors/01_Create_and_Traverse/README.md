# Creating and traversing a vector

## What you will learn

`vector` is a contiguous array whose size can change. `size()` counts elements; `capacity()` counts reserved slots. `push_back` takes amortized O(1), although an individual reallocation costs O(n).

## Analogy

A growing drawer can move to a larger drawer when full. Its compartments still start at index zero.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Sum: 60`.

## Practice

Call `reserve(10)` and check that it changes capacity without adding elements.

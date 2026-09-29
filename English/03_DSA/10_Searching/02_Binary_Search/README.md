# Binary search

## What you will learn

Requires ascending sorted data. Every comparison discards half of the range. Time O(log n), auxiliary memory O(1). Sorting has a separate cost. This version returns the first match; `lower_bound` is its standard alternative, while `binary_search` returns only existence.

## Analogy

Open a sorted guide at its middle and decide which half could contain the requested number.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Index: 1`.

## Practice

Draw the ranges when searching for 8 and explain why the algorithm cannot directly use 8, 1, 3.

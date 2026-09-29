# Linear search

## What you will learn

Inspect values from the start until finding a match. No sorting is required. Time O(n), auxiliary memory O(1). `optional` holds a position or `nullopt` for absence. Check before using `*result`; index 0 is valid. In applications you can use `find` instead.

## Analogy

Search a drawer for a key by checking every compartment.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Index: 1`.

## Practice

Search for the first value, the last value and a missing value.

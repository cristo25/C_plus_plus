# Selection sort

## What you will learn

Find the smallest pending value and swap it into the next position. Time O(n²), including sorted inputs; additional memory O(1). This implementation is not stable. Read `selectionSort` in `../Sorts.h`.

## Analogy

Always take the smallest card from a pile and put it in the next free slot.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `-1 0 3 3 5`.

## Practice

Count comparisons for four values and compare with bubble sort.

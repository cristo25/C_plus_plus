# Merge sort

## What you will learn

Split into halves, sort each half and merge them. Time O(n log n); auxiliary memory O(n) plus O(log n) recursive calls. Stable because ties select the left item first. Read `mergeSort` in `../Sorts.h`.

## Analogy

Divide sheets between two helpers, then combine their sorted piles by choosing the smaller available sheet.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `-1 0 3 3 5`.

## Practice

Draw splits and merges for six values. Observe that the range endpoint is excluded.

# Bubble sort

## What you will learn

Compare adjacent values and swap inverted pairs. Each pass moves the largest remaining value to the end. Average and worst-case time O(n²), best case O(n) for sorted data with the change flag. Additional memory O(1). Stable. Read `bubbleSort` in `../Sorts.h`.

## Analogy

Large bubbles rise toward an end; each pass moves the largest number there.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `-1 0 3 3 5`.

## Practice

Draw every pass for 4, 2, 3, 1.

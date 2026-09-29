# Insertion sort

## What you will learn

Maintain a sorted left section and insert each new value by shifting larger ones. Average and worst-case time O(n²); O(n) for sorted inputs. Additional memory O(1). Stable. Read `insertionSort` in `../Sorts.h`.

## Analogy

Sort a hand of cards by inserting each new card among the previous cards.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `-1 0 3 3 5`.

## Practice

Trace the shifts when inserting 2 into 1, 3, 4.

# One-dimensional arrays

## What you will learn

`array<int, 4>` stores four contiguous integers. Its size is fixed, with indices 0 through 3. `at()` checks bounds; `[]` requires a valid index. A traditional array is written `int data[4]` and has no `at()`.

## Analogy

An array is a drawer for one type of item, divided into numbered compartments starting at zero. Four compartments cannot hold a fifth item.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Original sum: 100`.

## Practice

Create a drawer of five grades and compute an average using floating-point division.

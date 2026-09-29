# Inserting and erasing in vectors

## What you will learn

`insert` and `erase` take iterators. `begin()` points to the first element; `end()` is past the last and must not be dereferenced. Middle insertion and erasure shift elements, costing O(n). Reallocation invalidates all pointers, references and iterators; erasure invalidates them from the erased position onward.

## Analogy

Making room in the middle of a drawer requires moving the items in the following compartments.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `20`. Validate a position before constructing an iterator such as `begin() + 1`.

## Practice

Remove every 20 using `remove` and `erase`. Explain the difference between rearranging elements and erasing them.

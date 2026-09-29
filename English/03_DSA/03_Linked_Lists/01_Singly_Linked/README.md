# Singly linked list

## What you will learn

Every node holds a value and the address of the next node. The last points to `nullptr`. There is no direct index access; traversing and searching cost O(n). The header appends values, removes the first matching value and releases all nodes. Appending here costs O(n).

## Analogy

A treasure hunt: every card contains a value and a clue pointing to the next card; the last says end.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `10 30`. The list owns its nodes, cannot be copied and releases them in its destructor.

## Practice

Draw links before and after removing the first node. Add a `contains` method.

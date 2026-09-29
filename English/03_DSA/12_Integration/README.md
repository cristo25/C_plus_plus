# Integration: processing tasks and querying routes

## What you will learn

Combine vector, linked list, stack, queue, priority queue, BST, hash table, graph, sorting and searching. Reuse the DSA headers. The queue defines processing order, the list keeps history, and the stack identifies the next undo action.

## Analogy

A workshop receives jobs, processes them, keeps a history, organizes priorities and consults a delivery map.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Processes `Practice`, `Read`, `Compile`; the last task is `Compile` and the minimum delivery cost is `2`.

The program's `assert` checks verify its behavior and stop execution on failure. Keep assertions enabled when studying. Operations that change state execute outside assertions and also run with `-DNDEBUG`.

## Practice

Add a fourth task and update the checks. Which structure would you choose for history alone? This demonstration combines structures to practice, not because every one is needed for that single requirement.

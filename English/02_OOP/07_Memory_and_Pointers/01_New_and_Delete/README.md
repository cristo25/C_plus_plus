# Manual dynamic memory

## What you will learn

`new` constructs a dynamic object and `delete` destroys it. Exactly one owner must be responsible for releasing it. Arrays made with `new[]` need `delete[]`. Usually prefer values, vectors or smart pointers.

## Analogy

Rent a locker, keep its address and return it exactly once. Returning it twice or visiting it afterward is an error.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `42`. This lesson isolates the mechanism; an early exit between `new` and `delete` could leak memory. The next lesson uses RAII.

## Practice

Draw when the integer's lifetime begins and ends. Do not read it after `delete`.

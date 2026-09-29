# Recursion

## What you will learn

A recursive function calls itself with a smaller problem. A base case stops the calls. Without a base case or progress, the call stack may be exhausted. `throw` signals an invalid argument; `try/catch` lets the example check the rejection.

## Analogy

Open a box containing a smaller box until reaching an empty one.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `120`. The range 0 through 12 keeps the factorial within a typical 32-bit `int`.

## Practice

Draw the calls and returns of `factorial(3)`, then write a version using `for`.

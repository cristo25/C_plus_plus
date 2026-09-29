# Your first program

## What you will learn

`#include` brings in declarations from the standard library. `main` is the entry point and `cout` writes to the console. Returning 0 means success. `using namespace std;` lets us write standard names without a prefix.

## Analogy

A program is a recipe. `main` tells the cook where to start, and each statement is a step.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Hello, C++!`.

## Practice

Replace the greeting with your name and add another line.

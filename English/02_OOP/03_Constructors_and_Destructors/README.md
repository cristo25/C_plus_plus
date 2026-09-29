# Constructors, destructors and RAII

## What you will learn

A constructor establishes initial state; a destructor runs when the object's lifetime ends. RAII ties a resource's lifetime to an object's lifetime. Strings, files and smart pointers already manage resources this way.

## Analogy

Opening a shop puts up its sign; closing it puts away the resources it managed.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output, in order: `Enter Ana`, `Leave Ana`, `Session ended`. The destructor prints to demonstrate its timing; do not add empty destructors without a reason.

## Practice

Construct two sessions in the same scope and observe reverse destruction order.

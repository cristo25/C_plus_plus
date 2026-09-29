# References and parameter passing

## What you will learn

`int&` is an alias for the original value. `const string&` lets you inspect a string without copying or modifying it. Initialize a reference when declaring it.

## Analogy

A reference is a second label on the same box, rather than a second box.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `5`.

## Practice

Change the parameter to `int number` and observe why the check fails.

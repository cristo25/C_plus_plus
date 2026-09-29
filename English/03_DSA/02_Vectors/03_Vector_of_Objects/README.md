# Vectors of objects

## What you will learn

A vector can store objects of one type. Members of a `struct` are public by default; members of a `class` are private by default. `const auto&` traverses without copying or changing objects.

## Analogy

The drawer now stores complete cards, each containing a name and a grade.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Ana: 9`, `Luis: 8` and `Eva: 10`.

## Practice

Compute the group's average and define what happens when the vector is empty.

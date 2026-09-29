# Hash tables with unordered_map

## What you will learn

`unordered_map` associates unique keys with values through hashing. Search and insertion cost O(1) on average and O(n) in the worst case. The library manages collisions and does not guarantee iteration order. `operator[]` can insert; use `find` for lookup alone.

## Analogy

A receptionist turns a key into a locker number and distinguishes records when several keys collide.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Ana`.

## Practice

Insert the same key twice with `emplace` and inspect the boolean result.

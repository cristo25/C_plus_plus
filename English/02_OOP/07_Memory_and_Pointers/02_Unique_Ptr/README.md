# Ownership with unique_ptr

## What you will learn

`unique_ptr` has one owner and releases its object automatically. `make_unique` constructs it. `move` transfers ownership; a `unique_ptr` cannot be copied. Use raw pointers only as observers when the target's lifetime is guaranteed.

## Analogy

A unique key controls the locker. When handing over that key, the former owner no longer holds it.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `42`. `shared_ptr` supports genuinely shared ownership; it is unnecessary here.

## Practice

Call `reset()` and check that the owner becomes empty. Do not use the observer afterward.

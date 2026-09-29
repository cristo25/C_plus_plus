# Inheritance

## What you will learn

A derived class reuses a base when an is-a relationship exists. Public inheritance preserves that relationship for callers. Prefer composition for has-a relationships. This base is not used to destroy derived objects through base pointers; the next lesson covers virtual destructors.

## Analogy

An electric bicycle is still a bicycle and adds a battery.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Speed: 5`.

## Practice

Use a loop to consume the battery and verify that its charge never becomes negative.

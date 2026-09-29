# Complexity: time and space

## What you will learn

Big O describes how work grows with input size, rather than exact seconds. Index access is O(1), visiting n elements is O(n), and repeatedly halving a problem takes O(log n) steps. Also count additional memory.

## Analogy

Finding a numbered compartment is direct. Inspecting every compartment takes longer as the cabinet grows. Halving a sorted guide discards many pages at once.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output compares `1024 visits` with `10 steps`. This illustrates growth, not elapsed time.

## Practice

Compare n = 8, 16 and 32. Draw the growth of n and the number of halvings.

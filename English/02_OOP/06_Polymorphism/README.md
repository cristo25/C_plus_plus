# Polymorphism and abstract classes

## What you will learn

`virtual` selects behavior using the actual object type. `= 0` declares an abstract operation; `override` verifies a correct override. A polymorphic base needs a virtual destructor when derived objects are destroyed through it.

## Analogy

The play-sound button works with different instruments, and each instrument decides which sound to make.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Strings` and `Percussion`.

## Practice

Add a `Flute` and use the same `play` function without changing it.

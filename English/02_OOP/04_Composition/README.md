# Composition

## What you will learn

An object can contain another: a has-a relationship. Members are constructed before the containing object's constructor body runs.

## Analogy

A car has an engine; a car is not a type of engine.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Engine on`.

## Practice

Add a method that turns the engine off through the car.

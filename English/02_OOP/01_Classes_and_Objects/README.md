# Classes and objects

## What you will learn

A class defines data and operations. An object is a concrete instance. `public` makes members accessible from outside; the next lesson protects state with `private`.

## Analogy

A class is a bicycle blueprint. Every bicycle built from it is an object with its own color.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Bicycle red: 5`.

## Practice

Add a braking method and check that the two objects keep independent states.

The blue bicycle is also displayed, at speed `0`, showing its independent state.

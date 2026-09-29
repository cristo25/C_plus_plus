# Integration: a library using objects

## What you will learn

Encapsulate a DAO using composition and practice polymorphism with two derived views. Reuse the previous header. `unique_ptr` owns the view, and a virtual destructor allows releasing its concrete type.

## Analogy

The library has a librarian and shows its catalog through either a detailed service window or a summary window.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `1: Learn C++` and `Books: 1`. The two views exist to demonstrate virtual dispatch; avoid adding interfaces for every class.

## Practice

Add a view that shows only titles and reuse the same DAO.

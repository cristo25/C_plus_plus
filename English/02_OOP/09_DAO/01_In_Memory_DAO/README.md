# In-memory DAO and CRUD

## What you will learn

DAO means Data Access Object: a data-access pattern, not a paradigm. `BookDAO` centralizes create, read, update and delete (CRUD). Call its operations without manipulating storage directly. For now, view `vector` as a growing collection; DSA studies it in detail. The educational DAO accepts at most 10,000 books, consistently across creation, saving and loading.

## Analogy

The librarian knows where books are stored. Ask for a book by its ID without inspecting every shelf.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `C++ step by step`. Data disappears when the program ends. The pointer returned by `findById` is temporary: do not retain it after creating, removing or loading records.

## Practice

Add two books and list `dao.all()`. Verify that updating an unknown ID returns `false`.

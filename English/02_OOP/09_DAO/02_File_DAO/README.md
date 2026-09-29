# Persisting a DAO in a file

## What you will learn

`save` serializes a snapshot and `load` validates it before replacing memory contents. `quoted` preserves spaces and quotes. Each snapshot begins with its book count. The example appends snapshots and reads the latest complete one. It reports damaged snapshots without silently discarding them.

## Analogy

The librarian photographs the catalog at closing time and restores its latest photograph when reopening.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `C++ with examples`. Appends one snapshot to `books_demo.txt` each run. Snapshots accept at most 10,000 books.

## Practice

Save a title containing quotes. Duplicate an ID in a copy of the file and verify rejection.

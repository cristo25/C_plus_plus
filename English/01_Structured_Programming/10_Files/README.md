# Reading and writing files

## What you will learn

`ofstream` writes and `ifstream` reads. Check opening, writing and reading. Objects close their files when leaving their scope. `ios::app` appends content.

## Analogy

Memory is a whiteboard erased when the program ends. A file is a notebook that keeps your notes.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Creates or appends to `notes_demo.txt` in the working directory. Every run adds `Study C++`.

## Practice

Add another note and read the file again. Explain what `ios::trunc` would do.

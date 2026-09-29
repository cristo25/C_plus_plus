# Strings

## What you will learn

`string` manages a sequence of characters. Concatenate, inspect its size, search and extract substrings. Check for `string::npos` before using a search result. `size()` counts bytes; UTF-8 characters can occupy multiple bytes.

## Analogy

A string is a necklace: every character is a bead. Join necklaces or take a section.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Hello, Ana`.

## Practice

Search for a missing word and avoid calling `substr` with `npos`.

The found substring is also displayed on another line: `Ana`.

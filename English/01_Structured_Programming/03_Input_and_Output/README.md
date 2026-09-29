# Reading and displaying input

## What you will learn

`getline(cin, text)` reads a whole line. An `istringstream` parses the age from that line. Validate the extraction, the allowed range and that no extra text remains. Reject empty or whitespace-only names. Handle invalid input with clear error messages.

## Analogy

The console is a service window: receive a request, check it, then return a response.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Enter `Ada`, then `20`. The response is `Hello, Ada. You are 20 years old.`. Negative ages, text, and `20abc` are rejected.

This example checks user input with ordinary conditions and returns exit code 1 for invalid input.

## Practice

Ask for a city with `getline`. If you mix `>>` and `getline`, consume the pending newline first.

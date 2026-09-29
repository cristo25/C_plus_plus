# Encapsulation and const

## What you will learn

`private` protects state. Public methods control valid changes. A `const` method queries without changing the object. Integer cents avoid floating-point rounding; this example limits its balance to 1,000,000 cents. You do not need a getter and setter for every attribute.

## Analogy

A piggy bank does not let you reach directly inside: its operations control deposits and withdrawals.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `300 cents`. Invalid amounts and withdrawals exceeding the balance are rejected.

## Practice

Try accessing `balanceCents` directly from `main` and withdrawing zero.

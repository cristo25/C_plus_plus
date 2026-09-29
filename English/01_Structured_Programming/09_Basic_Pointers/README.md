# Pointers: addresses and contents

## What you will learn

`&value` obtains an address, `int*` holds the address of an integer, and `*pointer` accesses its contents. `nullptr` means no target. The target must stay alive while you access it through the pointer. You do not need `new` yet.

## Analogy

The variable is a house and the pointer is a note containing its address. `&` writes down the address; `*` visits the house. An address does not guarantee the house still exists.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Contents: 25`. Never dereference `nullptr` or access a variable whose lifetime has ended.

## Practice

Create two pointers to the same integer and check that both observe changes.

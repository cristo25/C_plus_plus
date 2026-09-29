# Const, headers and compiling multiple files

## What you will learn

`Product.h` declares the class, `Product.cpp` defines its methods, and `main.cpp` uses it. `#ifndef` guards prevent repeated declarations. Compile both implementation files and link them. Include headers, never implementation files. Declarations live in `namespace course`, where `using namespace std;` does not introduce standard names into the includer's global namespace.

## Analogy

The header is a restaurant menu, the implementation is its kitchen, and `main` places the order.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Product.cpp -o program.exe
./program.exe
```

Output: `Notebook: 1250 cents`. Omitting `Product.cpp` causes missing definitions during linking.

## Practice

Declare a discounted-price query in the header and define it in `Product.cpp`.

## Const applied to a class

`main.cpp` creates a `const Product`: you can query its name and price without modifying it. Query methods put `const` after their parentheses in both the header and implementation, allowing calls on const objects. The name query returns `const string&` to avoid a copy and protect the original text.

Distinguish three uses: const values, read-only `const T&` parameters or results, and const methods that inspect object state. A price-changing method should not be const.

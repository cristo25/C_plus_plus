# Const and headers in structured programming

## What you will learn

`const` prevents changing a value after declaration. These grades and their average never change, so they are constants. `const array<int, 3>&` reads grades without copying or modifying them. `constexpr` allows compile-time evaluation; `inline constexpr` header constants can be shared across implementation files.

`Grades.h` declares functions and constants, `Grades.cpp` defines their operations, and `main.cpp` organizes execution. Splitting a program into files does not require a class.

## Analogy

The header is an instruction card describing available services. The implementation does the work. `const` puts glass over the drawer: you can inspect grades without moving them.

## Run the example

From this folder:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Grades.cpp -o program.exe
./program.exe
```

Output:

```text
Average: 9
Passed
```

Compile both `.cpp` files and include the header, never the implementation. Guards prevent repeated declarations, and the namespace groups course names. Grades outside 0 through 10 cause a message and exit code 1.

## Practice

Try assigning a new grade after declaration; compilation rejects it. Then change the **initializer** to `{4, 5, 6}` and observe `Failed`. Declare and define a highest-grade function that does not modify the array.

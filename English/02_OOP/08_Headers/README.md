# Const, headers and compiling multiple files

We will connect this topic’s pieces before solving its integration task. Each link contains the program, comments and a practice task with requirements.

## Const, headers and compiling multiple files

We will separate a class so several programs can use it. In Product.h we show its stored data and available operations; in Product.cpp we write how those operations work. From main we create a Product with a name and price. We store prices as whole cents to avoid small decimal-rounding differences. With const we protect the object and its queries. To run it we compile main.cpp together with Product.cpp; including the .h only announces the functions, not their bodies.

[Commented program](main.cpp).

**Practice.** Write a program with a Product class split into files.

- Store a name and a private price in cents.
- Declare the class in Product.h and its functions in Product.cpp.
- Read both values through const methods.
- Create two products from main and display their details.
- Reject a negative price.

[Back to the general guide](../../README.md).

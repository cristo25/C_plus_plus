# Const, headers and compiling multiple files

We will separate a class so several programs can use it. We can picture Product.h as a menu showing what a shop offers, and Product.cpp as the place where those tasks are done. From main we create a Product with a name and price. We store prices as whole cents to avoid small decimal-rounding differences. With const we protect the object and its queries. If we try a negative price, the constructor rejects the product with an error from <stdexcept>; <string> lets us store its name. To run it we compile main.cpp together with Product.cpp: including the .h only announces the functions.

[Commented program](main.cpp).

**Practice.** Write a program with a Product class split into files.

- Store a name and a private price in cents.
- Declare the class in Product.h and its functions in Product.cpp.
- Read both values through const methods.
- Create two products from main and display their details.
- Reject a negative price.

[Back to the general guide](../../README.md).

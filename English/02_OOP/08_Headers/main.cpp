// Const, headers and compiling multiple files
//
// We will separate a class so several programs can use it. In Product.h we show its stored data and
// available operations; in Product.cpp we write how those operations work. From main we create a
// Product with a name and price. We store prices as whole cents to avoid small decimal-rounding
// differences. With const we protect the object and its queries. To run it we compile main.cpp
// together with Product.cpp; including the .h only announces the functions, not their bodies.
//

#include "Product.h"
#include <iostream>

using namespace std;
using namespace course;

int main() {
    // A const object allows only methods that respect its state, such as these queries.
    const Product notebook("Notebook", 1250);

    cout << notebook.getName() << ": " << notebook.getPrice() << " cents\n";
}

// Const, headers and compiling multiple files
//
// Product.h declares the class, Product.cpp defines its methods, and main.cpp uses it. #ifndef
// guards prevent repeated declarations. Compile both implementation files and link them. Include
// headers, never implementation files. Declarations live in namespace course, where using
// namespace std; does not introduce standard names into the includer's global namespace.
//
// Analogy: The header is a restaurant menu, the implementation is its kitchen, and main places
// the order.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Product.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Declare a discounted-price query in the header and define it in Product.cpp.

#include "Product.h"
#include <iostream>

using namespace std;
using namespace course;

int main() {
    // A const object allows only methods that respect its state, such as these queries.
    const Product notebook("Notebook", 1250);

    cout << notebook.getName() << ": " << notebook.getPrice() << " cents\n";
}

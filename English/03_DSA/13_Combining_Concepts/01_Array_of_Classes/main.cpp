// 1. An array containing objects
//
// First decide what to store: products with a name and price. We reuse
// Product.h from OOP. array<Product, 3> contains three objects, like a drawer
// with three compartments holding complete products, rather than addresses.
// The array manages their lifetimes. const auto& lets us inspect each product
// without copying it or modifying it through that reference.
//
// Compile from this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../../02_OOP/08_Headers/Product.cpp -o program.exe
// Run: ./program.exe
//
// Practice: Change one price and predict the total. Explain why pointers are unnecessary here.

#include <array>
#include <iostream>
#include "../../../02_OOP/08_Headers/Product.h"

using namespace std;
using namespace course;

int main() {
    const array<Product, 3> products{
        Product("Notebook", 300),
        Product("Pencil", 100),
        Product("Book", 500)
    };

    long long total = 0;
    // Each reference is a temporary label for one of the three array objects.
    for (const Product& product : products) {
        cout << product.getName() << ": " << product.getPrice() << "\n";
        total += product.getPrice();
    }
    cout << "Total in cents: " << total << "\n";
}

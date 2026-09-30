// 1. An array containing objects
//
// We will store complete objects in an array. In Product products[3], each compartment contains a
// product with its name and price. We reuse Product.h from OOP. We can picture a drawer with three
// Minecraft blocks: each keeps its own data even though all share a type. We traverse through const
// Product& to read the original without copying or changing it. When the array ends, its contained
// objects end too.
//
// Practice: We will store complete products in an array.
// - We will create three products with names and prices.
// - We will traverse them to show and add their prices.

#include <iostream>
#include "../../../02_OOP/08_Headers/Product.h"

using namespace std;
using namespace course;

int main() {
    const Product products[3]{
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

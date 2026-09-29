// 5. An array of arrays of pointers
//
// A display has rows; each row has slots holding product address cards.
// array<array<Product*, 2>, 2> contains two rows of two pointers. Two cards
// can point to the same product; a nullptr slot is empty. This matrix
// is not Product**: it contains fixed-size arrays, rather than pointers to rows.
// The inventory owns the products; the display only shows positions. Changing
// the original object is visible through every card pointing to it.
//
// Compile from this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../../02_OOP/08_Headers/Product.cpp -o program.exe
// Run: ./program.exe
//
// Practice: Replace one slot with nullptr. Explain why counting slots does not count unique products.

#include <array>
#include <iostream>
#include "../../../02_OOP/08_Headers/Product.h"

using namespace std;
using namespace course;

int main() {
    array<Product, 2> products{
        Product("Notebook", 300),
        Product("Pencil", 100)
    };
    const array<array<Product*, 2>, 2> slots{
        array<Product*, 2>{&products.at(0), nullptr},
        array<Product*, 2>{&products.at(1), &products.at(0)}
    };

    // const protects the matrix cards, not their targets. This known target exists.
    *slots.at(0).at(0) = Product("Large notebook", 400);
    for (const auto& row : slots) {
        for (const Product* product : row) {
            if (product != nullptr) {
                // product->method() means (*product).method(). We read through const Product*.
                cout << product->getName() << " | ";
            } else {
                cout << "Empty | ";
            }
        }
        cout << "\n";
    }
}

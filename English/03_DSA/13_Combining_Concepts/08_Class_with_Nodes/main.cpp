// 8. A class manages struct nodes
//
// Shelf combines OOP and lists: it hides a chain of struct nodes; each node
// contains a Product class object and owns the next node through unique_ptr.
// The shelf owns the first node. Links are changed inside the class.
// first() lends const Node*, and getProduct() lends const Product&.
// The borrowed view must not outlive clear() or destruction of the shelf.
// Read Shelf.h: the header holds the shared implementation for these examples.
// Product.cpp must still be linked because its functions are defined outside its header.
//
// Compile from this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../../02_OOP/08_Headers/Product.cpp -o program.exe
// Run: ./program.exe
//
// Practice: Add three products and predict their order. Draw the chain of owners.

#include <iostream>
#include "../Shelf.h"

using namespace std;
using namespace course;

int main() {
    Shelf shelf("Stationery");
    shelf.add(Product("Notebook", 300));
    shelf.add(Product("Pencil", 100));

    const Shelf::Node* cursor = shelf.first();
    while (cursor != nullptr) {
        cout << cursor->getProduct().getName() << "\n";
        cursor = cursor->nextNode();
    }
    cout << "Total in cents: " << shelf.total() << "\n";
}

// 4. A vector of pointers: an inventory view
//
// The inventory is an array of objects; the view is a vector of their addresses.
// The view can grow and repeat a product without copying it. Reassigning a view
// pointer changes the selection, not the inventory. Product*& is a reference
// to a card and Product& a reference to its new target. Even if the vector
// relocates its cards while growing, the products in this local array stay put.
// The inventory must outlive the view.
//
// Compile from this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../../02_OOP/08_Headers/Product.cpp -o program.exe
// Run: ./program.exe
//
// Practice: Select a different product and explain which element changes and which stay the same.

#include <array>
#include <iostream>
#include <vector>
#include "../../../02_OOP/08_Headers/Product.h"

using namespace std;
using namespace course;

void selectProduct(Product*& selection, Product& replacement) {
    selection = &replacement;
}

int main() {
    array<Product, 3> products{
        Product("Notebook", 300),
        Product("Pencil", 100),
        Product("Book", 500)
    };
    vector<Product*> view{&products.at(0), &products.at(1)};
    // at(0) returns a reference to the stored pointer: int*& works the same way.
    selectProduct(view.at(0), products.at(2));
    view.push_back(&products.at(0));

    for (const Product* product : view) {
        if (product != nullptr) {
            cout << product->getName() << "\n";
        }
    }
    cout << "First inventory object: " << products.at(0).getName() << "\n";
}

// 5. An array of arrays of pointers
//
// We will arrange address cards in rows and columns. Product* slots[2][2] represents two rows of
// two addresses. With slots[0][1] we select a card; if it is not nullptr, we can follow it to the
// product. Two slots can show the same product, like two signs pointing to the same shop. Here we
// add const after * to fix the cards; we can still modify their products. A matrix is not
// Product**: it contains its rows, whereas a double pointer stores an address leading to another
// pointer.
//

#include <iostream>
#include "../../../02_OOP/08_Headers/Product.h"

using namespace std;
using namespace course;

int main() {
    Product products[2]{
        Product("Notebook", 300),
        Product("Pencil", 100)
    };
    Product* const slots[2][2]{
        {&products[0], nullptr},
        {&products[1], &products[0]}
    };

    // const protects the matrix cards, not their targets. This known target exists.
    *slots[0][0] = Product("Large notebook", 400);
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

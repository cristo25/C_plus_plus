// 4. A vector of pointers: an inventory view
//
// We will select products without copying them. We store products in an array and their addresses
// in vector<Product*>. We call this selection a view: it can grow or show a product several times
// without creating new products. With Product*& we give selectProduct another label for the
// original pointer, allowing it to change the destination. Receiving only Product* would change a
// copy of the card. Growing the address vector does not move these array products; they must keep
// existing while we read them.
//

#include <iostream>
// We store a collection that can grow using vector.
#include <vector>
#include "../../../02_OOP/08_Headers/Product.h"

using namespace std;
using namespace course;

void selectProduct(Product*& selection, Product& replacement) {
    selection = &replacement;
}

int main() {
    Product products[3]{
        Product("Notebook", 300),
        Product("Pencil", 100),
        Product("Book", 500)
    };
    vector<Product*> view{&products[0], &products[1]};
    // at(0) returns a reference to the stored pointer: int*& works the same way.
    selectProduct(view.at(0), products[2]);
    view.push_back(&products[0]);

    for (const Product* product : view) {
        if (product != nullptr) {
            cout << product->getName() << "\n";
        }
    }
    cout << "First inventory object: " << products[0].getName() << "\n";
}

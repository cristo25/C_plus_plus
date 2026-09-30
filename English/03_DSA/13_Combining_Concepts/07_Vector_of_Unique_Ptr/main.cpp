// 7. A vector of owners and an observer pointer
//
// We will separate the location of cards from that of products. In vector<unique_ptr<Product>>,
// each card is also responsible for releasing its product. When the vector needs more space it can
// move the cards; separately created products keep their addresses. With get we lend an address,
// not deletion responsibility. Removing the responsible card also destroys its product; before that
// we stop using every borrowed pointer. This differs from vector<Product>, where growth can move
// the products themselves.
//
// Practice: We will store products managed by unique_ptr.
// - We will create two products in a vector and inspect one through get.
// - We will stop using the borrowed pointer before deleting its product.

#include <iostream>
// We use unique_ptr to release its managed object automatically.
#include <memory>
// We store a collection that can grow using vector.
#include <vector>
#include "../../../02_OOP/08_Headers/Product.h"

using namespace std;
using namespace course;

int main() {
    vector<unique_ptr<Product>> owners;
    owners.push_back(make_unique<Product>("Notebook", 300));
    const Product* observer = owners.at(0).get();

    // We request more vector space: its cards move while their products remain in place.
    owners.reserve(owners.capacity() + 1);
    owners.push_back(make_unique<Product>("Pencil", 100));
    cout << boolalpha << "The product stays at the same address: " << (observer == owners.at(0).get()) << "\n";
    cout << observer->getName() << "\n";

    // Do not dereference the observer after erasing its owner.
    observer = nullptr;
    owners.erase(owners.begin());
    cout << "Remaining owners: " << owners.size() << "\n";
}

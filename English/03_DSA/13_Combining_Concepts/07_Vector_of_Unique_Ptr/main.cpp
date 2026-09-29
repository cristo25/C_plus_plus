// 7. A vector of owners and an observer pointer
//
// vector<unique_ptr<Product>> holds cards responsible for destroying
// their products. make_unique creates the managed object. get() lends its
// address without transferring ownership. When the vector reallocates,
// the owners move; their managed products keep their addresses. In contrast,
// vector<Product> can move objects and leave their pointers dangling when
// reallocating. Erasing a unique_ptr destroys its product: first we clear
// its observer. If there were more observers, all would need to be cleared.
//
// Compile from this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../../02_OOP/08_Headers/Product.cpp -o program.exe
// Run: ./program.exe
//
// Practice: Add a second observer and explain when it must also be cleared.

#include <iostream>
#include <memory>
#include <vector>
#include "../../../02_OOP/08_Headers/Product.h"

using namespace std;
using namespace course;

int main() {
    vector<unique_ptr<Product>> owners;
    owners.push_back(make_unique<Product>("Notebook", 300));
    const Product* observer = owners.at(0).get();

    // A larger capacity forces reallocation of the cards, not their managed products.
    owners.reserve(owners.capacity() + 1);
    owners.push_back(make_unique<Product>("Pencil", 100));
    cout << boolalpha << "The product stays at the same address: " << (observer == owners.at(0).get()) << "\n";
    cout << observer->getName() << "\n";

    // Do not dereference the observer after erasing its owner.
    observer = nullptr;
    owners.erase(owners.begin());
    cout << "Remaining owners: " << owners.size() << "\n";
}

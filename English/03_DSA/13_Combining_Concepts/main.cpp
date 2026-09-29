// Integration: owners, views, matrices and sorting
//
// This example combines the nine steps into one operation: show products
// in sorted order without reorganizing their inventory. A vector holds Shelf
// classes; each class owns struct nodes containing Product. We build a view
// of const Node*, sort it by price and select addresses for a matrix.
// const& parameters inspect owners; const Node*& changes a selection.
// Never delete nodes while borrowed views are in use. Repeated slots are not
// extra stock: calculate the total from the owners.
//
// Compile from this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp ../../02_OOP/08_Headers/Product.cpp -o program.exe
// Run: ./program.exe
//
// Practice: Sort by name and demonstrate that the original list order did not change.

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>
#include "Shelf.h"

using namespace std;
using namespace course;

// Reference to a card: change the caller's selection. The target is read-only.
void selectProduct(const Shelf::Node*& selection, const Shelf::Node* replacement) {
    selection = replacement;
}

long long total(const vector<Shelf>& shelves) {
    long long total = 0;
    for (const Shelf& shelf : shelves) {
        const long long subtotal = shelf.total();
        if (total > numeric_limits<long long>::max() - subtotal) {
            throw overflow_error("The inventory exceeds the long long range");
        }
        total += subtotal;
    }
    return total;
}

int main() {
    // First construct the owners: vector -> shelves -> nodes -> products.
    vector<Shelf> shelves;
    shelves.emplace_back("Stationery");
    shelves.at(0).add(Product("Notebook", 300));
    shelves.at(0).add(Product("Pencil", 100));
    shelves.emplace_back("Books");
    shelves.at(1).add(Product("Book", 500));

    // Then borrow addresses. Lists contain objects; the view contains only cards.
    vector<const Shelf::Node*> view;
    for (const Shelf& shelf : shelves) {
        const Shelf::Node* cursor = shelf.first();
        while (cursor != nullptr) {
            view.push_back(cursor);
            cursor = cursor->nextNode();
        }
    }

    // Sorting the view moves cards without changing links or moving products.
    sort(view.begin(), view.end(), [](const Shelf::Node* left, const Shelf::Node* right) {
        return left->getProduct().getPrice() < right->getProduct().getPrice();
    });
    for (const Shelf::Node* cursor : view) {
        cout << cursor->getProduct().getName() << ": "
             << cursor->getProduct().getPrice() << "\n";
    }

    const Shelf::Node* selection = nullptr;
    selectProduct(selection, view.at(0));
    // The matrix displays two unique products in three slots: selection appears twice.
    const array<array<const Shelf::Node*, 2>, 2> slots{
        array<const Shelf::Node*, 2>{selection, nullptr},
        array<const Shelf::Node*, 2>{view.at(1), selection}
    };
    size_t occupied = 0;
    for (const auto& row : slots) {
        for (const Shelf::Node* cursor : row) {
            if (cursor != nullptr) {
                ++occupied;
            }
        }
    }

    // Integration check: the inventory and its links kept their data and order.
    const long long before = total(shelves);
    if (view.size() != 3 || before != 900 || occupied != 3 ||
        selection->getProduct().getPrice() != 100 ||
        shelves.at(0).first()->getProduct().getPrice() != 100 ||
        shelves.at(0).first()->nextNode()->getProduct().getPrice() != 300) {
        cerr << "The integration example produced an unexpected result\n";
        return 1;
    }
    cout << "Inventory in cents: " << before << "\n";
    cout << "Occupied slots (may repeat products): " << occupied << "\n";

    // Clear the selection and view. They do not delete nodes because they are not owners.
    selection = nullptr;
    view.clear();
    // At scope exit, the matrix is destroyed before the shelves; no observer outlives its nodes.
}

// Integration: owners, views, matrices and sorting
//
// We will combine the layers to display sorted products without moving their original boxes. We
// store shelves in a vector; each shelf contains nodes and each node a product. We collect node
// addresses in view and sort only those cards by price. Then we choose cards for a display matrix.
// One card may appear several times: counting occupied slots does not count distinct products. We
// calculate total value from the shelves so a repeated display does not count the product twice.
//
// Practice: We will create an inventory with shelves and views.
// - We will store products in nodes on several shelves.
// - We will sort addresses to show a view without changing the original lists.

// We use sort to sort or change data order.
#include <algorithm>
#include <iostream>
// We use numeric_limits to check the largest allowed integer before adding.
#include <limits>
// We report errors with messages, such as invalid_argument for an invalid value.
#include <stdexcept>
// We store a collection that can grow using vector.
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
    shelves.push_back(Shelf("Stationery"));
    shelves[0].add(Product("Notebook", 300));
    shelves[0].add(Product("Pencil", 100));
    shelves.push_back(Shelf("Books"));
    shelves[1].add(Product("Book", 500));

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
    selectProduct(selection, view[0]);
    // The matrix displays two unique products in three slots: selection appears twice.
    const Shelf::Node* const slots[2][2]{
        {selection, nullptr},
        {view[1], selection}
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
        shelves[0].first()->getProduct().getPrice() != 100 ||
        shelves[0].first()->nextNode()->getProduct().getPrice() != 300) {
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

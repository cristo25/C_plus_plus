// Pointers: a box, a card and a card pointing to another card
//
// First we will distinguish a value from its address. A variable such as int is a box holding a
// whole number; a pointer is also a variable, but it holds another box's address. We can picture a
// finger pointing to the data. With & we obtain that address; with * we follow it to read or change
// the value. Copying a pointer copies the address, not the box. With int** we store a pointer's
// address: we follow two signs to reach the number.
//
// A reference is another label for the same box; a pointer can change destinations or hold nullptr,
// meaning it points nowhere. This helps us select a product or link nodes in lists, trees and
// graphs. We do not need new memory to point to an existing variable. Before following a pointer we
// check that it has a destination and that the data still exists: an address does not keep the box
// alive or automatically become nullptr when the box disappears.
//

#include <iostream>

using namespace std;

// The address card is copied; the integer it points to is still the original.
void addViaPointer(int* address) {
    if (address != nullptr) {
        ++*address;
    }
}

void redirectCopy(int* address, int& other) {
    // Only the local copy of the card is redirected. The caller's pointer does not change.
    address = &other;
    cout << "Local copy's destination: " << *address << "\n";
}

void redirectReference(int*& address, int& other) {
    // int*& gives another label to the caller's card: we can change its destination.
    address = &other;
}

void redirectDouble(int** address, int& other) {
    // int** holds a card's address. *address is that card, not the integer.
    if (address != nullptr) {
        *address = &other;
    }
}

int main() {
    cout << boolalpha;
    int box = 10;
    int anotherBox = 20;

    // &box obtains its address; int* declares a card pointing to an integer.
    int* address = &box;
    int* alias = address;
    *address = 25;
    cout << "Two cards, one box: " << *alias << "\n";

    addViaPointer(address);
    addViaPointer(nullptr);
    cout << "Box after int*: " << box << "\n";

    redirectCopy(address, anotherBox);
    cout << "Original card still points to box: " << (address == &box) << "\n";

    redirectReference(address, anotherBox);
    cout << "Reference redirected the card: " << (address == &anotherBox) << "\n";

    // &address points to the pointer variable. Dereferencing it twice would reach the integer.
    redirectDouble(&address, box);
    cout << "Double pointer returned it to box: " << (address == &box) << "\n";

    const int* readonly = &box;
    // The value cannot be changed through readonly; the card can change destination.
    readonly = &anotherBox;
    cout << "Reading through const int*: " << *readonly << "\n";

    int* const fixedAddress = &box;
    // The card cannot be redirected; the value at its destination can be modified.
    *fixedAddress = 30;
    cout << "Writing through int* const: " << box << "\n";

    // nullptr does not destroy box or clear other cards. Each observer is independent.
    address = nullptr;
    alias = nullptr;
}

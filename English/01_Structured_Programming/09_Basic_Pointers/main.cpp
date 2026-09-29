// Pointers: a box, a card and a card pointing to another card
//
// The variable is a box; a pointer is a card holding its address.
// & obtains an address and * follows it once. int** lets you locate a card,
// read it and then reach the box. Copying a card does not copy the box.
// A pointer does not keep its target alive: the local integers own themselves here.
// nullptr means no target; never dereference it. A non-null pointer can also
// dangle if its object has died. Do not return addresses of local variables.
// You do not need new to observe objects that already exist.
//
// Compile from this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
// Run: ./program.exe
//
// Practice: Add const int* const and explain which two things can no longer change.

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
    // int*& aliases the caller's card: we can change its destination.
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

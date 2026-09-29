// 3. An array of cards pointing to integers
//
// Now the drawer holds cards: array<int*, 3>. Each card can point to an
// integer living outside the array. The array contains the pointers,
// but does not own the integers. *addresses.at(0) follows the first card
// and changes red; assigning addresses.at(0) only changes that card.
// nullptr leaves a compartment without a target. Destroying the cards does not
// destroy the boxes, and copying the cards preserves the same targets.
//
// Compile from this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
// Run: ./program.exe
//
// Practice: Point two cards at red and change red through one of them.

#include <array>
#include <iostream>

using namespace std;

int main() {
    int red = 2;
    int blue = 5;
    array<int*, 3> addresses{&red, &blue, nullptr};

    // * changes the target integer. red goes from 2 to 7.
    *addresses.at(0) = 7;
    // Without * we change the card. red remains 7.
    addresses.at(0) = &blue;
    for (const int* address : addresses) {
        if (address != nullptr) {
            cout << *address << "\n";
        } else {
            cout << "No target\n";
        }
    }
    cout << "Red still contains: " << red << "\n";
}

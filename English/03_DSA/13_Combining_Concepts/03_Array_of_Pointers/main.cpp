// 3. An array of cards pointing to integers
//
// We will store addresses instead of integers. In int* addresses[3] we have three cards: each can
// point to a box outside the array. With *addresses[0] we follow the first card and change red;
// with addresses[0] = &blue we change only the card. Two cards can point to the same box, or hold
// nullptr when no box is selected. The array holds the pointers but does not delete the local
// integers they point to.
//
// Practice: We will use cards that point to numbers.
// - We will store three pointers in an array and point two of them at one number.
// - We will check for nullptr before reading the pointed-to number.

#include <iostream>

using namespace std;

int main() {
    int red = 2;
    int blue = 5;
    int* addresses[3]{&red, &blue, nullptr};

    // * changes the target integer. red goes from 2 to 7.
    *addresses[0] = 7;
    // Without * we change the card. red remains 7.
    addresses[0] = &blue;
    for (const int* address : addresses) {
        if (address != nullptr) {
            cout << *address << "\n";
        } else {
            cout << "No target\n";
        }
    }
    cout << "Red still contains: " << red << "\n";
}

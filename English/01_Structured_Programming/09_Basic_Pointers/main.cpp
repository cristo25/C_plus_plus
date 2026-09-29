// Pointers: addresses and contents
//
// &value obtains an address, int* holds the address of an integer, and *pointer accesses its
// contents. nullptr means no target. The target must stay alive while you access it through the
// pointer. You do not need new yet.
//
// Analogy: The variable is a house and the pointer is a note containing its address. & writes
// down the address; * visits the house. An address does not guarantee the house still exists.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Create two pointers to the same integer and check that both observe changes.

#include <iostream>

using namespace std;

int main() {
    int box = 10;
    // & obtains the box's address; the pointer locates that same integer.
    int* address = &box; // Non-owning: box manages its own lifetime.
    // * accesses the value: modifying it through the pointer also changes the box.
    *address = 25;

    int* withoutTarget = nullptr;
    // nullptr means no target; never read through a null pointer.
    if (withoutTarget != nullptr) {
        cout << *withoutTarget << "\n";
    }
    cout << "Contents: " << *address << "\n";
}

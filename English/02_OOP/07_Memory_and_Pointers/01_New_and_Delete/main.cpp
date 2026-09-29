// Manual dynamic memory
//
// new constructs a dynamic object and delete destroys it. Exactly one owner must be responsible
// for releasing it. Arrays made with new[] need delete[]. Usually prefer values, vectors or
// smart pointers.
//
// Analogy: Rent a locker, keep its address and return it exactly once. Returning it twice or
// visiting it afterward is an error.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Draw when the integer's lifetime begins and ends. Do not read it after delete.

#include <iostream>

using namespace std;

int main() {
    // new allocates an integer and returns its address; this example releases it manually.
    int* number = new int(42);

    cout << *number << "\n";
    // Release the new allocation once; the pointer no longer refers to a live object.
    delete number;
    number = nullptr; // Avoid accidentally reusing this address.
}

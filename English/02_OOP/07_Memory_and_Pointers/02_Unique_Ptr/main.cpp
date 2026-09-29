// Ownership with unique_ptr
//
// unique_ptr has one owner and releases its object automatically. make_unique constructs it.
// move transfers ownership; a unique_ptr cannot be copied. Use raw pointers only as observers
// when the target's lifetime is guaranteed.
//
// Analogy: A unique key controls the locker. When handing over that key, the former owner no
// longer holds it.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Call reset() and check that the owner becomes empty. Do not use the observer
// afterward.

#include <iostream>
#include <memory>
#include <utility>

using namespace std;

int main() {
    auto owner = make_unique<int>(42);
    // The observer accesses the value but does not release it: it must not use delete.
    int* observer = owner.get();
    // move transfers ownership; the previous owner becomes empty while the value stays alive.
    auto newOwner = move(owner);

    cout << *observer << "\n";
} // newOwner releases the integer; observer becomes invalid.

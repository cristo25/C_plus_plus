// Ownership with unique_ptr
//
// We will give one tool responsibility for releasing the box. With unique_ptr from <memory>, we
// keep that responsibility alongside the address. make_unique creates the data; get lends us its
// address for reading. That borrowed pointer must not release it. When the program ends, owner
// releases the integer automatically. This helps us avoid forgetting delete.
//

#include <iostream>
// We use unique_ptr to release its managed object automatically.
#include <memory>

using namespace std;

int main() {
    auto owner = make_unique<int>(42);
    // The observer accesses the value but does not release it: it must not use delete.
    int* observer = owner.get();
    cout << *observer << "\n";
} // owner releases the integer; observer becomes invalid.

// Practice: let's store a quantity with unique_ptr.
// - Create the integer with make_unique and borrow its address with get.
// - Print the value through the borrowed pointer.
// - Let unique_ptr release the integer at the end without calling delete.

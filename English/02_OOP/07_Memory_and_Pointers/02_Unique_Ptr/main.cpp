// Ownership with unique_ptr
//
// We will give one tool responsibility for releasing the box. With unique_ptr from <memory>, we
// keep that responsibility alongside the address. make_unique creates the data; get lends us its
// address for reading. That borrowed pointer must not release it. With move from <utility>, we
// transfer responsibility to newOwner and leave the old owner empty. When the new owner ends, the
// integer is released automatically. This helps us avoid forgetting delete.
//

#include <iostream>
// We use unique_ptr to release its managed object automatically.
#include <memory>
// We use move to transfer data or responsibility for releasing it.
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

#include <iostream>
#include <memory>
#include <utility>

using namespace std;

int main() {
    auto owner = make_unique<int>(42);
    int* observer = owner.get();
    auto newOwner = move(owner);

    cout << *observer << "\n";
} // newOwner releases the integer; observer becomes invalid.

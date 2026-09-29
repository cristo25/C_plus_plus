// One-dimensional arrays
//
// We will store several whole numbers in one drawer. With int drawer[4] we reserve four
// compartments of the same type. We count from zero: drawer[0] is the first and drawer[3] the last.
// Brackets choose a slot; they do not check that it exists, so we never use drawer[4]. We visit the
// slots to add their values and then change the second. This array has a fixed size and needs no
// additional library.
//

#include <iostream>

using namespace std;

int main() {
    // A four-compartment drawer for integers: indexes 0, 1, 2 and 3; its size is fixed.
    int drawer[4]{10, 20, 30, 40};
    int sum = 0;
    for (int value : drawer) {
        sum += value;
    }
    // at(1) is the second compartment and checks the index. The sum was computed before this
    // change.
    drawer[1] = 25;

    cout << "Original sum: " << sum << "\n";
}

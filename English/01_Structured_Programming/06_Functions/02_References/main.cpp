// Value, reference and const reference
//
// We will compare a copy with a reference. If a variable is a box, passing by value hands over
// another box with the same contents. With int& we attach another label to the original box:
// changing the value through that label changes the original. A reference stays attached to the
// same box from its creation; assigning another value changes the contents, not the box it refers
// to. With const int& we can read through the label but cannot write. The box must keep existing
// while we use it.
//

#include <iostream>
// We store and work with text using string.
#include <string>

using namespace std;

// By value: the function receives a separate box containing a copy.
void changeCopy(int copy) {
    copy = 99;
    cout << "Inside the copy: " << copy << "\n";
}

// By reference: this name is another label attached to the original box.
void changeOriginal(int& box) {
    ++box;
}

// const prevents modifying the string through this parameter; no copy is made.
size_t length(const string& text) {
    return text.size();
}

int main() {
    int box = 4;
    changeCopy(box);
    cout << "Original after passing by value: " << box << "\n";

    // No & at the call: the parameter declaration determines how it is passed.
    changeOriginal(box);
    cout << "Original after passing by reference: " << box << "\n";

    int& alias = box;
    int other = 8;
    // Assigning to the alias changes box. It does not rebind the alias to other.
    alias = other;
    ++alias;
    cout << "Box through alias: " << box << "; other: " << other << "\n";

    const int& readonly = box;
    // The const view does not freeze box: the original name can still modify it.
    box = 12;
    cout << "Const view observes: " << readonly << "\n";

    const string text = "C++";
    cout << "Length without copying: " << length(text) << "\n";
}

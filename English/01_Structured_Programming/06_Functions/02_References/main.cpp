// Value, reference and const reference
//
// A variable is a box. Passing by value supplies a second box; passing by
// reference supplies another label for the same box. A reference is initialized
// and stays bound to the same object: assigning a value changes that object.
// const T& is a label that permits reading, but not writing through that access.
// The object must remain alive while the reference is used.
//
// Compile from this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
// Run: ./program.exe
//
// Practice: Predict each output. Replace int& with int and observe what stops changing.

#include <iostream>
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

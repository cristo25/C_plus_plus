// A stack using vector
//
// A stack follows LIFO: last in, first out. Use push_back, back and pop_back; check empty before
// accessing or removing a value.
//
// Analogy: A stack of plates accepts and removes plates at its top.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Push three values and pop them in a loop until the stack is empty.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> stackValues;

    stackValues.push_back(10);
    stackValues.push_back(20);
    // Before reading back or removing it, check that a top element exists.
    if (!stackValues.empty()) {
        const int topValue = stackValues.back();
        stackValues.pop_back();

        cout << "Removed: " << topValue << "\n";
    }
}

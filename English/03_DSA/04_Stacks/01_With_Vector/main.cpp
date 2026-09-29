// A stack using vector
//
// We will use a vector like a stack of plates: we add and remove only at the top. With push_back we
// add, with back we inspect the last value, and with pop_back we remove it. The last item in is the
// first out. Before reading or removing we check that the stack is not empty. If we need the
// removed value, we save it before pop_back because that operation does not return it.
//

#include <iostream>
// We store a collection that can grow using vector.
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

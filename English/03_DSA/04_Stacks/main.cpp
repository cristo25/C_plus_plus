// Stacks
//
// We will compare a stack built with vector against one using stack. We put 1, 2 and 3 into both
// and remove from the top. In both, 3 must come out first. We are practicing the removal order:
// that rule defines a stack even when we use different storage tools.
//
// Practice: We will compare two stacks of actions.
// - We will store the same actions with vector and stack.
// - We will remove them and check that the last one added leaves first.

#include <iostream>
// We store a stack: with stack, the last item in comes out first.
#include <stack>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;

int main() {
    vector<int> manual;
    stack<int> adapter;
    for (int value : {1, 2, 3}) {
        manual.push_back(value);
        adapter.push(value);
    }
    // Both stacks remove from the top: last in, first out.
    while (!manual.empty()) {
        cout << manual.back() << ' ';
        manual.pop_back();
        adapter.pop();
    }
    cout << "\n";
}

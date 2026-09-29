// The stack adapter
//
// We will use stack, the <stack> tool that directly provides stack operations. push adds at the
// top, top reads the top, and pop removes it. We can picture an undo history: the last action we
// performed is the first one we examine. Here we show which action would be undone; removing it
// from history does not itself change a real document.
//

#include <iostream>
// We store a stack: with stack, the last item in comes out first.
#include <stack>
// We store and work with text using string.
#include <string>

using namespace std;

int main() {
    stack<string> history;
    history.push("Write");
    history.push("Delete");
    if (!history.empty()) {

        // top reads the last value; pop removes it without returning the value.
        cout << "Undo: " << history.top() << "\n";
        history.pop();
    }
}

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<string> history;
    history.push("Write");
    history.push("Delete");
    if (!history.empty()) {

        cout << "Undo: " << history.top() << "\n";
        history.pop();
    }
}

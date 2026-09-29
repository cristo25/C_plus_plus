// FIFO queue
//
// We will serve a line in arrival order. With queue from <queue>, we add at the back using push,
// inspect the first using front and remove it using pop. We can picture people waiting at a service
// desk. Before serving we check empty. We also call “first in, first out” FIFO; those letters
// simply abbreviate the same rule.
//

#include <iostream>
// We serve by arrival with queue or by importance with priority_queue.
#include <queue>
// We store and work with text using string.
#include <string>

using namespace std;

int main() {
    queue<string> row;
    row.push("Ana");
    row.push("Luis");

    // The front person arrived first; reading and removing require a nonempty queue.
    while (!row.empty()) {
        cout << "Serve: " << row.front() << "\n";
        row.pop();
    }
}

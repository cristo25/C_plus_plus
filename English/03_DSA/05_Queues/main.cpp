// Queues
//
// We will put the same values into a normal queue and a priority queue. After storing 2, 9 and 4,
// the first keeps that order; the second serves 9 first. This helps us decide which rule an
// application needs: respecting arrival or choosing by importance. Changing the structure changes
// the service rule even with identical data.
//

#include <iostream>
// We serve by arrival with queue or by importance with priority_queue.
#include <queue>

using namespace std;

int main() {
    queue<int> arrival;
    priority_queue<int> priority;
    for (int value : {2, 9, 4}) {
        arrival.push(value);
        priority.push(value);
    }
    cout << "FIFO: ";
    // FIFO preserves arrival order; the priority queue then selects the largest available value.
    while (!arrival.empty()) {
        cout << arrival.front() << ' ';
        arrival.pop();
    }
    cout << "\nPriority: ";
    while (!priority.empty()) {
        cout << priority.top() << ' ';
        priority.pop();
    }
    cout << "\n";
}

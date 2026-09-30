// Priority queues and heaps
//
// We will serve by importance instead of arrival. priority_queue puts the highest-priority value at
// the top: for integers this is normally the largest. To choose the smallest, such as a cost, we
// use greater<int>, a comparison rule from <functional>. We can picture a hospital's urgent cases:
// arriving first does not always mean being served first. With top we inspect the next value and
// with pop we remove it; data must be present.
//
// Practice: We will serve tasks by priority.
// - We will store at least three different priority levels.
// - We will show the removal order and compare it with arrival order.

// We select the smallest value first in a priority queue using greater.
#include <functional>
#include <iostream>
// We serve by arrival with queue or by importance with priority_queue.
#include <queue>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;

int main() {
    priority_queue<int> severity;
    // greater changes the criterion to put the smallest cost on top, like a line ordered by
    // urgency.
    priority_queue<int, vector<int>, greater<int>> cost;
    for (int value : {2, 9, 4}) {
        severity.push(value);
        cost.push(value);
    }

    cout << "Highest priority: " << severity.top() << "\n";
    cout << "Lowest cost: " << cost.top() << "\n";
}

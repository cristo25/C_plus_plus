#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<int> severity;
    priority_queue<int, vector<int>, greater<int>> cost;
    for (int value : {2, 9, 4}) {
        severity.push(value);
        cost.push(value);
    }

    cout << "Highest priority: " << severity.top() << "\n";
    cout << "Lowest cost: " << cost.top() << "\n";
}

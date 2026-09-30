// Loops
//
// We will use all three loops in one task. With for we collect amounts from several days; with
// while we remove groups of ten until finished; with do while we show at least one notice. We can
// picture a shop: we receive orders, deliver them and finally report completion. We choose each
// loop according to when its condition needs checking.
//

// Practice: Let's write an integrated program that organizes deliveries.
//
// - Add orders from three days with for.
// - Handle orders one at a time with while.
// - Show at least one final notice with do while.
// - Count and display completed orders.

#include <iostream>

using namespace std;

int main() {
    int total = 0;
    // for combines initialization, condition and update. This loop accumulates three days of
    // work.
    for (int day = 1; day <= 3; ++day) {
        total += day * 10;
    }
    int deliveries = 0;
    // while checks the condition before each delivery.
    while (total > 0) {
        total -= 10;
        ++deliveries;
    }
    int notices = 0;
    // do executes the body at least once and checks its condition afterward.
    do {
        ++notices;
    } while (notices < 1);

    cout << "Deliveries: " << deliveries << ", notices: " << notices << "\n";
}

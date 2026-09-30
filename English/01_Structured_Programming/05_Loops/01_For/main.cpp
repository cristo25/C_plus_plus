// Repeating with for
//
// We will repeat a task with for. Inside its parentheses we give the counter's starting value, the
// condition for continuing and the change after each turn. We can picture five numbered lockers: we
// inspect one, move ahead and repeat until the last. ++ increases the counter by one; the
// instructions inside the braces run each time.
//

// Practice: Let's write a program that displays the seven times table.
//
// - Use a counter from 1 to 10.
// - Calculate each multiplication inside the for loop.
// - Show each operation and result on its own line.

#include <iostream>

using namespace std;

int sumUpTo(int limit) {
    int sum = 0;
    // Start at 1, continue through limit, and increase number after each iteration.
    for (int number = 1; number <= limit; ++number) {
        sum += number;
    }
    return sum;
}

int main() {

    cout << sumUpTo(5) << "\n";
}

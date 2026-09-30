// Repeating with while
//
// We will repeat while a condition holds. With while we check before entering: if it is already
// false, we make no turns. We can picture a savings box that receives money until a target is
// reached. Inside the loop we change the savings; if the checked value never changes, we might
// repeat forever.
//

// Practice: Let's write a program that simulates weekly savings.
//
// - Start with zero savings.
// - Add 25 each week until reaching at least 110.
// - Count weeks and display savings after each one.
// - Show why the final amount can exceed the target.

#include <iostream>

using namespace std;

int main() {
    int savings = 0;
    int weeks = 0;
    // Check the condition before the body; weeks counts how many deposits are needed.
    while (savings < 100) {
        savings += 25;
        ++weeks;
    }

    cout << weeks << " weeks\n";
}

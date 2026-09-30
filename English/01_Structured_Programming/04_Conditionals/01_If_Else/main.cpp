// Decisions with if and else
//
// We will choose which instructions to run. With if we ask a question, such as whether someone is
// at least 18. If the answer is true, we enter its braces; with else we handle the other case. We
// can join questions: && requires both to be true, || requires at least one, and ! reverses an
// answer. We can picture two doors: the condition decides which one we take.
//

// Practice: Let's write a program that decides entry to an event.
//
// - Store an age and whether an adult accompanies the visitor.
// - Allow adults or accompanied minors to enter.
// - Display the reason for the decision.
// - Try ages 17 and 18.

#include <iostream>

using namespace std;

bool mayEnter(int age, bool hasTicket) {
    // && requires both conditions to be true: sufficient age and a ticket.
    return age >= 18 && hasTicket;
}

int main() {

    if (mayEnter(20, true)) {
        cout << "Entry allowed\n";
    } else {
        cout << "Entry denied\n";
    }
}

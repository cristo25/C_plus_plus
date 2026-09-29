// Decisions with if and else
//
// A condition evaluates to true or false. if, else if and else select a branch. Combine
// conditions with &&, || and !.
//
// Analogy: A fork in the road sends you along a different path depending on the sign.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Allow accompanied minors and test the boundary at age 18.

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

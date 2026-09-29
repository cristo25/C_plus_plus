// Encapsulation and const
//
// private protects state. Public methods control valid changes. A const method queries without
// changing the object. Integer cents avoid floating-point rounding; this example limits its
// balance to 1,000,000 cents. You do not need a getter and setter for every attribute.
//
// Analogy: A piggy bank does not let you reach directly inside: its operations control deposits
// and withdrawals.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Try accessing balanceCents directly from main and withdrawing zero.

#include <iostream>

using namespace std;

class PiggyBank {
    int balanceCents = 0; // Integer cents avoid rounding errors.
// balance is private by default in class. Only validated methods can change it.
public:
    bool deposit(int cents) {
        if (cents <= 0 || cents > 1000000 - balanceCents) {
            return false;
        }
        balanceCents += cents;
        return true;
    }
    bool withdraw(int cents) {
        if (cents <= 0 || cents > balanceCents) {
            return false;
        }
        balanceCents -= cents;
        return true;
    }
    // const after the parentheses promises that this query does not modify the object.
    int balance() const {
        return balanceCents;
    }
};

int main() {
    PiggyBank savings;
    if (savings.deposit(-5)) {
        return 1;
    }
    if (!(savings.deposit(500))) {
        return 1;
    }
    if (savings.withdraw(600)) {
        return 1;
    }
    if (!(savings.withdraw(200))) {
        return 1;
    }

    cout << savings.balance() << " cents\n";
}

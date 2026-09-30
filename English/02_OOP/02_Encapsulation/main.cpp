// Encapsulation and const
//
// We will protect a savings-box balance. Instead of allowing any change from main, we keep it
// inside the class and provide deposit and withdraw operations. Each function checks its rules
// before changing the balance. We call this encapsulation: keeping data and its rules behind
// controlled operations. Inside class, members are private unless we write public. With balance()
// const we can read without changing the savings: const after a function promises to respect the
// object's data.
//

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
    if (!savings.deposit(500)) {
        return 1;
    }
    if (savings.withdraw(600)) {
        return 1;
    }
    if (!savings.withdraw(200)) {
        return 1;
    }

    cout << savings.balance() << " cents\n";
}

// Practice: let's create an Account class whose balance changes only through its functions.
// - Reject negative deposits and withdrawals larger than the balance.
// - Add a const function that reads the balance.
// - Show the balance after one valid deposit and one valid withdrawal.

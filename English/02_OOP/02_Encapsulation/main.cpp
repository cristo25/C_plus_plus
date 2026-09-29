#include <iostream>

using namespace std;

class PiggyBank {
    int balanceCents = 0; // Integer cents avoid rounding errors.
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

#include <iostream>

using namespace std;

int main() {
    int total = 0;
    for (int day = 1; day <= 3; ++day) {
        total += day * 10;
    }
    int deliveries = 0;
    while (total > 0) {
        total -= 10;
        ++deliveries;
    }
    int notices = 0;
    do {
        ++notices;
    } while (notices < 1);

    cout << "Deliveries: " << deliveries << ", notices: " << notices << "\n";
}

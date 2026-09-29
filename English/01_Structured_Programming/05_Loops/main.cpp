// Loops
//
// Compare when each loop checks its condition. The integration example accumulates jobs,
// processes them and issues a notice: 6 deliveries and 1 notice.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe

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

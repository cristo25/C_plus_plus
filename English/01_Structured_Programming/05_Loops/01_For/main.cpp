#include <iostream>

using namespace std;

int sumUpTo(int limit) {
    int sum = 0;
    for (int number = 1; number <= limit; ++number) {
        sum += number;
    }
    return sum;
}

int main() {

    cout << sumUpTo(5) << "\n";
}

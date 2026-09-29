#include <iostream>

using namespace std;

int main() {
    int savings = 0;
    int weeks = 0;
    while (savings < 100) {
        savings += 25;
        ++weeks;
    }

    cout << weeks << " weeks\n";
}

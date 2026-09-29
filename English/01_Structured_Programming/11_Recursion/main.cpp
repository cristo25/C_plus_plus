#include <iostream>
#include <stdexcept>

using namespace std;

int factorial(int n) {
    if (n < 0 || n > 12) {
        throw invalid_argument("Use a number between 0 and 12");
    }
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {

    try {
        cout << factorial(5) << "\n";
    } catch (const invalid_argument& error) {
        cerr << error.what() << "\n";
        return 1;
    }
}

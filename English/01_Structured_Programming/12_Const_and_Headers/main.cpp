#include "Grades.h"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace course;

int main() {
    const array<int, 3> grades{8, 9, 10};
    try {
        const double average = calculateAverage(grades);
        cout << "Average: " << average << "\n";
        if (hasPassed(average)) {
            cout << "Passed\n";
        } else {
            cout << "Failed\n";
        }
    } catch (const invalid_argument& error) {
        cerr << error.what() << "\n";
        return 1;
    }
}

// Arrays
//
// We will combine a one-dimensional array with a matrix. In grades we store two students with three
// grades each; in averages we store one result per student. We visit a row, add its grades and
// divide by three. With static_cast<double> we treat the sum as a decimal number before dividing,
// keeping the fractional part of the average.
//

#include <iostream>

using namespace std;

int main() {
    // Each row holds one student's three grades; positions start at zero.
    int grades[2][3]{{8, 9, 10}, {7, 8, 9}};
    double averages[2]{};
    for (size_t row = 0; row < 2; ++row) {
        int sum = 0;
        for (int grade : grades[row]) {
            sum += grade;
        }
        // Convert the sum to double so the average keeps its fractional part.
        averages[row] = static_cast<double>(sum) / 3;
    }

    for (double average : averages) {
        cout << average << "\n";
    }
}

// Arrays
//
// We will combine a one-dimensional array with a matrix. In grades we store two students with three
// grades each; in averages we store one result per student. We visit a row, add its grades and
// divide by 3.0. Writing 3.0 keeps the decimal part of the average.
//

// Practice: Let's write an integrated student-grade program.
//
// - Store three students with four grades each in a matrix.
// - Store the three averages in another array.
// - Display each average and whether the student passed.
// - Keep grades between 0 and 10.

#include <iostream>

using namespace std;

int main() {
    // Each row holds one student's three grades; positions start at zero.
    int grades[2][3]{{8, 9, 10}, {7, 8, 9}};
    double averages[2]{};
    for (int row = 0; row < 2; ++row) {
        int sum = 0;
        for (int grade : grades[row]) {
            sum += grade;
        }
        // With 3.0 the result keeps its decimal part.
        averages[row] = sum / 3.0;
    }

    for (double average : averages) {
        cout << average << "\n";
    }
}

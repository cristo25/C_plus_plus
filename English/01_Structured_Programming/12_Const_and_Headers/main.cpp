// Const and headers in structured programming
//
// We will split a program into files. In Grades.h we list the functions we can use; in Grades.cpp
// we write their steps; from main.cpp we call them. We can picture the .h as a menu and the .cpp as
// the kitchen. With const we protect the grades from accidental changes. We also pass their count:
// when receiving an array as a parameter, the function needs that count to know where to stop. With
// #ifndef, #define and #endif we avoid reading the same header twice inside a file being compiled.
//

#include "Grades.h"
#include <iostream>

using namespace std;
using namespace course;

int main() {
    const int grades[3]{8, 9, 10};
    double average = 0;
    // We receive true for valid grades; the average is written through a reference.
    if (!calculateAverage(grades, 3, average)) {
        cerr << "Grades must be between 0 and 10.\n";
        return 1;
    }
    cout << "Average: " << average << "\n";
    if (hasPassed(average)) {
        cout << "Passed\n";
    } else {
        cout << "Failed\n";
    }
}

// Const and headers in structured programming
//
// const prevents changing a value after declaration. These grades and their average never
// change, so they are constants. const array<int, 3>& reads grades without copying or modifying
// them. constexpr allows compile-time evaluation; inline constexpr header constants can be
// shared across implementation files.
// Grades.h declares functions and constants, Grades.cpp defines their operations, and main.cpp
// organizes execution. Splitting a program into files does not require a class.
//
// Analogy: The header is an instruction card describing available services. The implementation
// does the work. const puts glass over the drawer: you can inspect grades without moving them.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Grades.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Try assigning a new grade after declaration; compilation rejects it. Then change the
// initializer to {4, 5, 6} and observe Failed. Declare and define a highest-grade function that
// does not modify the array.

#include "Grades.h"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace course;

int main() {
    // Grades are fixed when declared; calculateAverage receives a read-only reference.
    const array<int, 3> grades{8, 9, 10};
    try {
        // The declaration is in the .h and the work is defined in the other .cpp.
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

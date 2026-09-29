// Arrays
//
// Start with one drawer, then a cabinet. The integration example stores grades in a matrix and
// averages in an array: 9 and 8.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe

#include <array>
#include <iostream>

using namespace std;

int main() {
    // Each row holds one student's three grades; positions start at zero.
    array<array<int, 3>, 2> grades{{{8, 9, 10}, {7, 8, 9}}};
    array<double, 2> averages{};
    for (size_t row = 0; row < grades.size(); ++row) {
        int sum = 0;
        for (int grade : grades.at(row)) {
            sum += grade;
        }
        // Convert the sum to double so the average keeps its fractional part.
        averages.at(row) = static_cast<double>(sum) / grades.at(row).size();
    }

    for (double average : averages) {
        cout << average << "\n";
    }
}

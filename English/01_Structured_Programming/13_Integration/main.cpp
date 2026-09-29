// Integration: a grade report
//
// Combine functions, references, strings, arrays, loops, conditions, a non-owning pointer and a
// file. Read the steps in order: compute, classify, build the report and save it.
//
// Analogy: A teacher checks a drawer of grades, calculates an average and records it in a
// notebook.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Add another student and a function returning the highest grade. Keep grades between
// 0 and 10.

#include <array>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

double average(const array<int, 3>& grades) {
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}

int main() {
    const array<int, 3> grades{8, 9, 10};
    const double result = average(grades);
    // This pointer reads the average without modifying it or owning its memory.
    const double* observer = &result;

    string status;
    if (*observer >= 6) {
        status = "Passed";
    } else {
        status = "Failed";
    }
    const string report = "Ana: " + to_string(*observer) + " - " + status;
    // The report combines an array, function, condition, string and file in one workflow.
    ofstream output("report_demo.txt", ios::app);
    if (!output) {
        cerr << "Could not open the report.\n";
        return 1;
    }
    output << report << "\n";
    output.close();
    if (!output) {
        cerr << "Could not save.\n";
        return 1;
    }

    cout << report << "\n";
}

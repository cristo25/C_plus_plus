// Integration: a grade report
//
// We will bring the lessons together in a report. We store grades in an array, calculate their
// average with a function and use a condition to decide whether the student passed. With observer
// we store the result's address: *observer reads that same average. We then build a text line and
// append it to a file. We can follow the data all the way through: grades, calculation, decision,
// message and saved notebook.
//

// We read and save files using ifstream and ofstream.
// Practice: Let's write an integrated school-report program.
//
// - Store names and three grades per student using string and arrays.
// - Calculate averages and highest grades with functions.
// - Use a reference to update a value and a pointer to read another.
// - Classify each average with if and display the report.
// - Save reports without erasing earlier ones.
// - Separate declarations and functions into a .h and a .cpp.

#include <fstream>
#include <iostream>
// We store and work with text using string.
#include <string>

using namespace std;

bool average(const int grades[], int count, double& outputAverage) {
    if (count <= 0) {
        return false;
    }
    long long sum = 0;
    for (int index = 0; index < count; ++index) {
        const int grade = grades[index];
        if (grade < 0 || grade > 10) {
            return false;
        }
        sum += grade;
    }
    outputAverage = static_cast<double>(sum) / count;
    return true;
}

int main() {
    const int grades[3]{8, 9, 10};
    double result = 0;
    if (!average(grades, 3, result)) {
        cerr << "Invalid grades.\n";
        return 1;
    }
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

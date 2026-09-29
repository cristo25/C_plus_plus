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
    const double* observer = &result;

    string status;
    if (*observer >= 6) {
        status = "Passed";
    } else {
        status = "Failed";
    }
    const string report = "Ana: " + to_string(*observer) + " - " + status;
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

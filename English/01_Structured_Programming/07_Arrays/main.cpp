#include <array>
#include <iostream>

using namespace std;

int main() {
    array<array<int, 3>, 2> grades{{{8, 9, 10}, {7, 8, 9}}};
    array<double, 2> averages{};
    for (size_t row = 0; row < grades.size(); ++row) {
        int sum = 0;
        for (int grade : grades.at(row)) {
            sum += grade;
        }
        averages.at(row) = static_cast<double>(sum) / grades.at(row).size();
    }

    for (double average : averages) {
        cout << average << "\n";
    }
}

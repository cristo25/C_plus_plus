#include "Grades.h"
#include <stdexcept>

using namespace std;

namespace course {
    double calculateAverage(const array<int, 3>& grades) {
        int sum = 0;
        for (const int grade : grades) {
            if (grade < MIN_GRADE || grade > MAX_GRADE) {
                throw invalid_argument("Grades must be between 0 and 10");
            }
            sum += grade;
        }
        return static_cast<double>(sum) / grades.size();
    }

    bool hasPassed(double average) {
        return average >= PASSING_GRADE;
    }
} // namespace course

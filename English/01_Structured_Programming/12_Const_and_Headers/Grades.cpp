#include "Grades.h"

using namespace std;

namespace course {
    bool calculateAverage(const int grades[], int count, double& result) {
        if (count <= 0) {
            return false;
        }
        long long sum = 0;
        // Validate each grade before adding it; const prevents us from changing the grades through this parameter.
        for (int index = 0; index < count; ++index) {
            const int grade = grades[index];
            if (grade < MIN_GRADE || grade > MAX_GRADE) {
                return false;
            }
            sum += grade;
        }
        // We convert before dividing so we keep the average's decimal places.
        result = static_cast<double>(sum) / count;
        return true;
    }

    bool hasPassed(double average) {
        return average >= PASSING_GRADE;
    }
} // namespace course

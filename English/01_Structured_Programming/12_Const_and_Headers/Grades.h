// These guards prevent processing the header twice in one translation unit.
#ifndef COURSE_GRADES_H
#define COURSE_GRADES_H
#include <array>

namespace course {
    using namespace std;

    // Shared constants: every file uses the same grading rules.
    inline constexpr int MIN_GRADE = 0;
    inline constexpr int MAX_GRADE = 10;
    inline constexpr int PASSING_GRADE = 6;

    // Declare the service here; Grades.cpp contains its definition.
    double calculateAverage(const array<int, 3>& grades);
    bool hasPassed(double average);
} // namespace course
#endif

#ifndef COURSE_GRADES_H
#define COURSE_GRADES_H
#include <array>

namespace course {
    using namespace std;

    inline constexpr int MIN_GRADE = 0;
    inline constexpr int MAX_GRADE = 10;
    inline constexpr int PASSING_GRADE = 6;

    double calculateAverage(const array<int, 3>& grades);
    bool hasPassed(double average);
} // namespace course
#endif

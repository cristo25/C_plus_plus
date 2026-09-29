// With these three instructions we avoid reading this header twice while compiling one file.
#ifndef COURSE_GRADES_H
#define COURSE_GRADES_H

namespace course {
    using namespace std;

    // Shared constants: every file uses the same grading rules.
    const int MIN_GRADE = 0;
    const int MAX_GRADE = 10;
    const int PASSING_GRADE = 6;

    // Declare the service here; Grades.cpp contains its definition.
    bool calculateAverage(const int grades[], int count, double& result);
    bool hasPassed(double average);
} // namespace course
#endif

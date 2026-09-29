#ifndef COURSE_QUERIES_H
#define COURSE_QUERIES_H
#include <cstddef>
#include <vector>

namespace course {
    using namespace std;

    inline constexpr int EXAMPLE_LIMIT = 7;
    size_t countAbove(const vector<int>& data, int limit);
} // namespace course
#endif

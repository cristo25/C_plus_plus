// With inline we allow these definitions to be shared from the header across several files.

#ifndef COURSE_QUERIES_H
#define COURSE_QUERIES_H
// We use size_t to count elements and represent nonnegative positions.
#include <cstddef>
// We store a collection that can grow using vector.
#include <vector>

namespace course {
    using namespace std;

    inline constexpr int EXAMPLE_LIMIT = 7;
    // A query reads const vector<int>&; sorting requires vector<int>& to modify it.
    size_t countAbove(const vector<int>& data, int limit);
} // namespace course
#endif

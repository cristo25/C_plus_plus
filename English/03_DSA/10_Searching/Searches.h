#ifndef COURSE_SEARCHES_H
#define COURSE_SEARCHES_H
#include <cstddef>
#include <optional>
#include <vector>

namespace course {
    using namespace std;

    inline optional<size_t> linearSearch(const vector<int>& data, int target) {
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i] == target) {
                return i;
            }
        }
        return nullopt;
    }

    // Precondition: data sorted in ascending order; return the first match.
    inline optional<size_t> binarySearch(const vector<int>& data, int target) {
        size_t startIndex = 0, endIndex = data.size(); // Range [startIndex, endIndex).
        while (startIndex < endIndex) {
            size_t middle = startIndex + (endIndex - startIndex) / 2;
            if (data[middle] < target) {
                startIndex = middle + 1;
            } else {
                endIndex = middle;
            }
        }
        if (startIndex < data.size() && data[startIndex] == target) {
            return startIndex;
        }
        return nullopt;
    }
} // namespace course

#endif

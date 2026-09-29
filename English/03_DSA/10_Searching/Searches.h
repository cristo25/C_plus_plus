// With inline we allow these definitions to be shared from the header across several files.

#ifndef COURSE_SEARCHES_H
#define COURSE_SEARCHES_H
// We use size_t to count elements and represent nonnegative positions.
#include <cstddef>
// We store a result that may be missing: optional holds a value or is empty.
#include <optional>
// We store a collection that can grow using vector.
#include <vector>

namespace course {
    using namespace std;

    inline optional<size_t> linearSearch(const vector<int>& data, int target) {
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i] == target) {
                return i;
            }
        }
        // Not found is not index zero: optional represents absence explicitly.
        return nullopt;
    }

    // Before searching we need values sorted from smallest to largest. We return the first match.
    inline optional<size_t> binarySearch(const vector<int>& data, int target) {
        size_t startIndex = 0, endIndex = data.size(); // Range [startIndex, endIndex).
        while (startIndex < endIndex) {
            size_t middle = startIndex + (endIndex - startIndex) / 2;
            // If the middle value is smaller, discard its left side; otherwise keep the
            // candidate.
            if (data[middle] < target) {
                startIndex = middle + 1;
            } else {
                endIndex = middle;
            }
        }
        // At the end, check for a match: the boundary can also fall at the end of the vector.
        if (startIndex < data.size() && data[startIndex] == target) {
            return startIndex;
        }
        return nullopt;
    }
} // namespace course

#endif

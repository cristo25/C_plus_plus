#include "Queries.h"

using namespace std;

namespace course {
    size_t countAbove(const vector<int>& data, int limit) {
        size_t count = 0;
        for (int value : data) {
            if (value > limit) {
                ++count;
            }
        }
        return count;
    }
} // namespace course

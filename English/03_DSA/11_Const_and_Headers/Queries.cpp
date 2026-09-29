#include "Queries.h"
#include <algorithm>

using namespace std;

namespace course {
    size_t countAbove(const vector<int>& data, int limit) {
        return count_if(data.begin(), data.end(), [limit](int value) {
            return value > limit;
        });
    }
} // namespace course

#include "Searches.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    vector<int> data{8, 3, 5, 1, 3};
    assert(linearSearch(data, 8).value() == 0);
    sort(data.begin(), data.end());
    for (int target : {0, 1, 3, 5, 8, 99}) {
        assert(linearSearch(data, target) == binarySearch(data, target));
    }
    cout << "Index of 8 after sorting: " << binarySearch(data, 8).value() << "\n";
}

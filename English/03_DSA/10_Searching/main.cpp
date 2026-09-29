// Searching
//
// Search first without ordering, then after sorting. The integration example compares both
// searches on sorted values and shows the original index of 8 changing from 0 to 4.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe

#include "Searches.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    vector<int> data{8, 3, 5, 1, 3};
    // assert checks an integration result; it does not perform application operations.
    assert(linearSearch(data, 8).value() == 0);
    // Binary search requires sorted input; sorting changes the original positions of values.
    sort(data.begin(), data.end());
    for (int target : {0, 1, 3, 5, 8, 99}) {
        assert(linearSearch(data, target) == binarySearch(data, target));
    }
    cout << "Index of 8 after sorting: " << binarySearch(data, 8).value() << "\n";
}

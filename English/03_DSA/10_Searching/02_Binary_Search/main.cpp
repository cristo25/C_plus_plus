#include "../Searches.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    const vector<int> data{1, 3, 3, 5, 8};
    auto position = binarySearch(data, 3);

    if (position) {
        cout << "Index: " << *position << "\n";
    }
}

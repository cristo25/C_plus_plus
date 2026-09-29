#include "../Searches.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    const vector<int> data{8, 3, 5, 3};
    auto position = linearSearch(data, 3);

    if (position) {
        cout << "Index: " << *position << "\n";
    }
}

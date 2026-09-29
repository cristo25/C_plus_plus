#include "Queries.h"
#include <iostream>

using namespace std;
using namespace course;

int main() {
    const vector<int> data{9, 4, 10, 6};
    const size_t count = countAbove(data, EXAMPLE_LIMIT);
    cout << "Values above " << EXAMPLE_LIMIT << ": " << count << "\n";
    for (const int value : data) {
        cout << value << ' ';
    }
    cout << "\n";
}

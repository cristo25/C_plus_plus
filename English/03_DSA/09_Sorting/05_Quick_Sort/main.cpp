#include "../Sorts.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    vector<int> data{5, -1, 3, 3, 0};
    quickSort(data);

    for (int value : data) {
        cout << value << ' ';
    }
    cout << "\n";
}

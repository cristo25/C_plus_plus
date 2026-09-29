// Selection sort
//
// We will find the smallest remaining value and place it at the beginning of the unsorted section.
// Then we repeat with the rest. We can picture choosing the smallest book from a pile and placing
// it in a row. Even if numbers are already sorted, we keep finding each group’s minimum; with n
// values, work grows roughly like n times n (O(n²)). Swapping distant positions can change the
// order of tied elements.
//

#include "../Sorts.h"
#include <iostream>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace course;

int main() {
    vector<int> data{5, -1, 3, 3, 0};
    // Find the smallest pending value and put it in the next sorted position.
    selectionSort(data);

    for (int value : data) {
        cout << value << ' ';
    }
    cout << "\n";
}

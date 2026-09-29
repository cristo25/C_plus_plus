// Sorting algorithms
//
// We will check five ways of sorting using identical inputs. We create a copy for each algorithm
// and compare its result with sort. We include empty, negative, repeated and already sorted data.
// We keep function addresses to call each algorithm in the same way: just as a pointer can point to
// a box, a function pointer can point to a task we can run. If a comparison fails, we display the
// problem and stop.
//

#include "Sorts.h"
// We use sort to sort or change data order.
#include <algorithm>
#include <iostream>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace course;

int main() {
    // A function pointer lets us test all five algorithms through the same call.
    using SortFunction = void (*)(vector<int>&); // Address of a function.
    for (SortFunction sortValues :
         {bubbleSort, selectionSort, insertionSort, mergeSort, quickSort}) {
        for (const vector<int>& input :
             vector<vector<int>>{{}, {1}, {4, 3, 2, 1}, {1, 2, 3, 4}, {2, 2, -1, 0, 2}}) {
            auto result = input;
            auto expected = input;
            sort(expected.begin(), expected.end());
            sortValues(result);
            if (!(result == expected)) {
                cerr << "The check did not produce the expected result.\n";
                return 1;
            }
        }
    }
    cout << "All 5 algorithms match sort on 5 inputs.\n";
}

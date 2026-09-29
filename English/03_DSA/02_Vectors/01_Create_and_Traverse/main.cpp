// Creating and traversing a vector
//
// We will use a drawer whose number of slots can grow: vector<int>, from <vector>. With push_back
// we add at the end; with size we check how many values it holds. We visit the numbers to add them.
// When reserved space fills up, the vector can move to another block with its data; old addresses
// no longer work. Usually adding at the end takes little work; spreading those moves across many
// insertions keeps average work per insertion bounded (amortized O(1): we spread growth costs
// across many operations).
//

#include <iostream>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;

int main() {
    vector<int> numbers{10, 20};
    // Add a compartment to the expandable drawer. A reallocation may move every element.
    numbers.push_back(30);
    int sum = 0;
    for (int number : numbers) {
        sum += number;
    }

    cout << "Sum: " << sum << "\n";
}

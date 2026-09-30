// Creating and traversing a vector
//
// We will use a drawer whose number of slots can grow: vector<int>, from <vector>. With push_back
// we add at the end; with size we check how many values it holds. We visit the numbers to add
// them. When reserved space fills up, the vector can move to another block with its data; old
// addresses no longer work. We do not need a bigger drawer every time we add a value; usually we
// just fill the next slot.
//
// Practice: We will collect grades in a vector.
// - We will add at least four numbers with push_back.
// - We will traverse the vector to calculate and display their sum.

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

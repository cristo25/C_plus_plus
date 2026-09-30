// Vectors
//
// We will combine creation, editing and object records in a task list. Each Task stores its name
// and whether it is finished. We insert a task, mark another and remove a record. We can picture a
// notebook where we add and remove rows. The vector keeps the data together, but positions may
// change when inserting or erasing; we therefore distinguish a task's name from its current
// position.
//
// Practice: We will create a task list that we can edit.
// - We will store the names and states of at least three tasks in a vector.
// - We will add, finish and remove a task; then show the result.

#include <iostream>
// We store and work with text using string.
#include <string>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;

struct Task {
    string name;
    bool done;
};

int main() {
    vector<Task> tasks{{"Read", false}, {"Practice", false}};
    // Inserting in the middle shifts following elements; the vector preserves their order.
    tasks.insert(tasks.begin() + 1, {"Compile", false});
    tasks.at(0).done = true;
    tasks.erase(tasks.begin());
    for (const auto& task : tasks) {
        cout << task.name << "\n";
    }
}

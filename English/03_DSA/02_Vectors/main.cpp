#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Task {
    string name;
    bool done;
};

int main() {
    vector<Task> tasks{{"Read", false}, {"Practice", false}};
    tasks.insert(tasks.begin() + 1, {"Compile", false});
    tasks.at(0).done = true;
    tasks.erase(tasks.begin());
    for (const auto& task : tasks) {
        cout << task.name << "\n";
    }
}

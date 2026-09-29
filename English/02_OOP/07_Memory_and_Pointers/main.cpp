#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Student {
    string name;

public:
    explicit Student(const string& initialName) : name(initialName) {
    }
    const string& getName() const {
        return name;
    }
};

int main() {
    auto owner = make_unique<Student>("Ana");
    const Student* observer = owner.get();

    cout << observer->getName() << "\n";
    owner.reset();
    observer = nullptr;
}

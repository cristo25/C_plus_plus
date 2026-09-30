// Memory and pointers in OOP
//
// We can picture Student as a box holding a name and observer as the address of that box. We create the
// student with make_unique and borrow its address with get. With observer->getName() we follow that
// address to read the name. Before calling reset we stop using the borrowed address and set observer
// to nullptr. Then reset releases the student. The borrowed pointer never deletes it.
//

#include <iostream>
// We use unique_ptr to release its managed object automatically.
#include <memory>
// We store and work with text using string.
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
    // get returns an observer: unique_ptr remains the owner and releases the object.
    const Student* observer = owner.get();

    cout << observer->getName() << "\n";
    // We stop using the borrowed address before destroying the object with reset.
    observer = nullptr;
    owner.reset();
}

// Practice: let's create a Pet class and manage it with unique_ptr.
// - Store a name and read it with a const function.
// - Read the name through an address borrowed with get.
// - Stop using that address before releasing the pet with reset.

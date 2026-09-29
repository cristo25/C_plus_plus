// Constructors, destructors and RAII
//
// A constructor establishes initial state; a destructor runs when the object's lifetime ends.
// RAII ties a resource's lifetime to an object's lifetime. Strings, files and smart pointers
// already manage resources this way.
//
// Analogy: Opening a shop puts up its sign; closing it puts away the resources it managed.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Construct two sessions in the same scope and observe reverse destruction order.

#include <iostream>
#include <string>

using namespace std;

class Session {
    string user;

public:
    // The constructor initializes the object; explicit prevents unexpected implicit conversions.
    explicit Session(const string& name) : user(name) {
        cout << "Enter " << user << "\n";
    }
    // The destructor runs automatically when the object's lifetime ends.
    ~Session() {
        cout << "Leave " << user << "\n";
    }
    const string& name() const {
        return user;
    }
};

int main() {
    {
        Session session("Ana");

    } // The lifetime of session ends here.
    cout << "Session ended\n";
}

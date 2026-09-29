#include <iostream>
#include <string>

using namespace std;

int main() {
    string name = "Ana";
    string greeting = "Hello, " + name;
    auto position = greeting.find(name);

    cout << greeting << "\n";
    if (position != string::npos) {
        cout << greeting.substr(position) << "\n";
    }
}

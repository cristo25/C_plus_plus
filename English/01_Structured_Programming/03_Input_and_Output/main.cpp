#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string name;
    int age = 0;
    cout << "Name: ";
    if (!getline(cin, name) || name.find_first_not_of(" \t\r") == string::npos) {
        cerr << "Invalid name.\n";
        return 1;
    }
    cout << "Age: ";
    string line;
    if (!getline(cin, line)) {
        return 1;
    }
    istringstream parser(line);
    if (!(parser >> age) || age < 0 || age > 130 || !(parser >> ws).eof()) {
        cerr << "Invalid age.\n";
        return 1;
    }
    cout << "Hello, " << name << ". You are " << age << " years old.\n";
}

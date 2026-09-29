// Reading and displaying input
//
// getline(cin, text) reads a whole line. An istringstream parses the age from that line.
// Validate the extraction, the allowed range and that no extra text remains. Reject empty or
// whitespace-only names. Handle invalid input with clear error messages.
//
// Analogy: The console is a service window: receive a request, check it, then return a response.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Ask for a city with getline. If you mix >> and getline, consume the pending newline
// first.

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string name;
    int age = 0;
    cout << "Name: ";
    // getline captures the whole line, including spaces; reject an empty name.
    if (!getline(cin, name) || name.find_first_not_of(" \t\r") == string::npos) {
        cerr << "Invalid name.\n";
        return 1;
    }
    cout << "Age: ";
    string line;
    if (!getline(cin, line)) {
        return 1;
    }
    // Parse the text as a number. ws consumes spaces; eof rejects trailing text such as 20abc.
    istringstream parser(line);
    if (!(parser >> age) || age < 0 || age > 130 || !(parser >> ws).eof()) {
        cerr << "Invalid age.\n";
        return 1;
    }
    cout << "Hello, " << name << ". You are " << age << " years old.\n";
}

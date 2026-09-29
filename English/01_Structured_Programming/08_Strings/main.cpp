// Strings
//
// string manages a sequence of characters. Concatenate, inspect its size, search and extract
// substrings. Check for string::npos before using a search result. size() counts bytes; UTF-8
// characters can occupy multiple bytes.
//
// Analogy: A string is a necklace: every character is a bead. Join necklaces or take a section.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Search for a missing word and avoid calling substr with npos.
// The found substring is also displayed on another line: Ana.

#include <iostream>
#include <string>

using namespace std;

int main() {
    string name = "Ana";
    string greeting = "Hello, " + name;
    // find returns the index of the matching text, or string::npos when absent.
    auto position = greeting.find(name);

    cout << greeting << "\n";
    if (position != string::npos) {
        // Extract the substring only after checking that a match exists.
        cout << greeting.substr(position) << "\n";
    }
}

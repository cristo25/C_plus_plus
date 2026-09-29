// Reading and writing files
//
// ofstream writes and ifstream reads. Check opening, writing and reading. Objects close their
// files when leaving their scope. ios::app appends content.
//
// Analogy: Memory is a whiteboard erased when the program ends. A file is a notebook that keeps
// your notes.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Add another note and read the file again. Explain what ios::trunc would do.

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const string path = "notes_demo.txt";
    {
        // ios::app appends to preserve lines that already exist.
        ofstream output(path, ios::app);
        if (!output) {
            cerr << "Could not open the file.\n";
            return 1;
        }
        output << "Study C++\n";
        output.close();
        if (!output) {
            cerr << "Save error.\n";
            return 1;
        }
    }
    // Writing has finished: open a reading stream for the same file.
    ifstream input(path);
    if (!input) {
        cerr << "Could not read.\n";
        return 1;
    }
    string line;
    while (getline(input, line)) {
        cout << line << "\n";
    }
    // Reaching the end is normal; a different reading failure must be reported.
    if (!input.eof()) {
        cerr << "Read error.\n";
        return 1;
    }
}

// Reading and writing files
//
// We will keep text after the program ends. We can think of memory as a whiteboard and a file as a
// notebook we put away. With ofstream we open the notebook for writing; with ifstream we open it
// for reading. Both tools come from <fstream>. We use ios::app to add lines at the end without
// erasing earlier ones. We check that each file opened, then read one line at a time. The loop ends
// when there is no next line.
//
// Practice: Let's keep a study diary.
//
// - Add an activity to the end of a file.
// - Read the file and display every activity.
// - Show a message if the file cannot be opened for writing or reading.

// With fstream we can read and write files.
#include <fstream>
#include <iostream>
// With string we keep the file path and each line we read.
#include <string>

using namespace std;

int main() {
    const string path = "notes_demo.txt";
    {
        // With ios::app we add a line without erasing the others.
        ofstream output(path, ios::app);
        if (!output) {
            cerr << "Could not open the file.\n";
            return 1;
        }
        output << "Study C++\n";
        // The file closes on its own when we leave this block.
    }
    // We open the same file to read it.
    ifstream input(path);
    if (!input) {
        cerr << "Could not read.\n";
        return 1;
    }
    string line;
    while (getline(input, line)) {
        cout << line << "\n";
    }
    // The file also closes on its own when the program ends.
    return 0;
}

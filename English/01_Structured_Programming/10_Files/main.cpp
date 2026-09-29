// Reading and writing files
//
// We will keep text after the program ends. We can think of memory as a whiteboard and a file as a
// notebook we put away. With ofstream we open the notebook for writing; with ifstream we open it
// for reading. Both tools come from <fstream>. We use ios::app to add lines at the end without
// erasing earlier ones. We check that opening and saving succeeded; when reading reaches the end,
// eof tells us there is no more data.
//

// We read and save files using ifstream and ofstream.
#include <fstream>
#include <iostream>
// We store and work with text using string.
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

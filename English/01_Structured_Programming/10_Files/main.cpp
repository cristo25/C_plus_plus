#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const string path = "notes_demo.txt";
    {
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
    ifstream input(path);
    if (!input) {
        cerr << "Could not read.\n";
        return 1;
    }
    string line;
    while (getline(input, line)) {
        cout << line << "\n";
    }
    if (!input.eof()) {
        cerr << "Read error.\n";
        return 1;
    }
}

// Your first program
//
// We will start by displaying a message. We can picture the program as a recipe: inside main we
// write the steps, and with cout we send text to the screen. We put text in quotation marks; \n
// starts a new output line. With return 0 we indicate that the program finished successfully.
// Compiling turns this text file into a program the computer can run.
//

#include <iostream>

// Lets us write cout without the standard namespace prefix.
using namespace std;

// Execution starts in main; returning 0 reports success.
int main() {
    cout << "Hello, C++!\n";
    return 0;
}

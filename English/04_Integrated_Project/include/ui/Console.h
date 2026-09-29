#ifndef PROJECT_CONSOLE_H
#define PROJECT_CONSOLE_H

// We receive an input source: keyboard, file or text in memory.
#include <istream>
// We receive an output destination: screen, file or text in memory.
#include <ostream>
#include "services/Library.h"

namespace project {
    using namespace std;

    // The interface requests data and presents results; Library applies the rules.
    class Console {
        Library& library;
        istream& input;
        ostream& output;
    public:
        Console(Library& library, istream& input, ostream& output);
        void run();
    };
}

#endif

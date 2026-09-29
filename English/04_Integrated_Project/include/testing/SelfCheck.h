#ifndef PROJECT_SELF_CHECK_H
#define PROJECT_SELF_CHECK_H

// We receive an output destination: screen, file or text in memory.
#include <ostream>

namespace project {
    using namespace std;
    // Checks use conditions that remain active when compiling the final version.
    int selfCheck(ostream& output);
}

#endif

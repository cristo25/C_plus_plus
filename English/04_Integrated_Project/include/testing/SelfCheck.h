#ifndef PROJECT_SELF_CHECK_H
#define PROJECT_SELF_CHECK_H

#include <ostream>

namespace project {
    using namespace std;
    // One runnable check via --self-test; it also works with NDEBUG.
    int selfCheck(ostream& output);
}

#endif

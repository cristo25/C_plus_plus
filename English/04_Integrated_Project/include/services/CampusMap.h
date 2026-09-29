#ifndef PROJECT_CAMPUS_MAP_H
#define PROJECT_CAMPUS_MAP_H

// We store a result that may be missing: optional holds a value or is empty.
#include <optional>
// We store and work with text using string.
#include <string>
// We store a collection that can grow using vector.
#include <vector>
#include "models/Delivery.h"
#include "../../../03_DSA/08_Graphs/Graph.h"

namespace project {
    using namespace std;
    using namespace course;

    class CampusMap {
        // Six fixed buildings; edges hold minutes, rather than physical distance.
        const vector<string> labels;
        Graph network;
    public:
        CampusMap();
        const vector<string>& names() const;
        const Graph& map() const;
        vector<size_t> reachable(size_t source) const;
        optional<Route> shortestRoute(size_t source, size_t target) const;
    };
}

#endif

#ifndef PROJECT_CAMPUS_MAP_H
#define PROJECT_CAMPUS_MAP_H

#include <array>
#include <optional>
#include <string>
#include <vector>
#include "models/Delivery.h"
#include "../../../03_DSA/08_Graphs/Graph.h"

namespace project {
    using namespace std;
    using namespace course;

    class CampusMap {
        // Six fixed buildings; edges hold minutes, rather than physical distance.
        const array<string, 6> labels;
        Graph network;
    public:
        CampusMap();
        const array<string, 6>& names() const;
        const Graph& map() const;
        vector<size_t> reachable(size_t source) const;
        optional<Route> shortestRoute(size_t source, size_t target) const;
    };
}

#endif

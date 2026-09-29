#include "services/CampusMap.h"
#include <algorithm>
#include <stdexcept>
#include <tuple>

namespace project {
    using namespace std;

    CampusMap::CampusMap()
        : labels{"Library", "Laboratory", "Engineering", "Administration", "Residences", "Disconnected annex"},
          network(labels.size()) {
        const array<tuple<size_t, size_t, int>, 6> connections{
            tuple<size_t, size_t, int>{0, 1, 4},
            tuple<size_t, size_t, int>{0, 2, 1},
            tuple<size_t, size_t, int>{2, 1, 1},
            tuple<size_t, size_t, int>{1, 3, 3},
            tuple<size_t, size_t, int>{2, 3, 6},
            tuple<size_t, size_t, int>{3, 4, 2}
        };
        // Each road works in both directions; annex 5 stays isolated to practice that case.
        for (const auto& [source, target, minutes] : connections) {
            network.connect(source, target, minutes);
            network.connect(target, source, minutes);
        }
    }

    const array<string, 6>& CampusMap::names() const {
        return labels;
    }

    const Graph& CampusMap::map() const {
        return network;
    }

    vector<size_t> CampusMap::reachable(size_t source) const {
        return bfs(network, source);
    }

    optional<Route> CampusMap::shortestRoute(size_t source, size_t target) const {
        (void)labels.at(target);
        const auto result = shortestPaths(network, source);
        if (result.distances.at(target) == INFINITY_DISTANCE) {
            return nullopt;
        }
        Route route{result.distances.at(target), {}};
        size_t cursor = target;
        // Follow predecessor cards backward from the destination, then reverse the traversal.
        while (cursor != source) {
            route.stops.push_back(cursor);
            const auto previous = result.predecessors.at(cursor);
            if (!previous) {
                throw logic_error("The route has an invalid predecessor link");
            }
            cursor = *previous;
        }
        route.stops.push_back(source);
        reverse(route.stops.begin(), route.stops.end());
        return route;
    }
}

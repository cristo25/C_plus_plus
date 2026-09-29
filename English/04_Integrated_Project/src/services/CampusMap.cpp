#include "services/CampusMap.h"
// We use reverse to sort or change data order.
#include <algorithm>
// We report errors with messages, such as invalid_argument for an invalid value.
#include <stdexcept>

namespace project {
    using namespace std;

    CampusMap::CampusMap()
        : labels{"Library", "Laboratory", "Engineering", "Administration", "Residences", "Disconnected annex"},
          network(labels.size()) {
        struct Connection {
            size_t source;
            size_t target;
            int minutes;
        };
        const Connection connections[6]{
            Connection{0, 1, 4},
            Connection{0, 2, 1},
            Connection{2, 1, 1},
            Connection{1, 3, 3},
            Connection{2, 3, 6},
            Connection{3, 4, 2}
        };
        // Each road works in both directions; annex 5 stays isolated to practice that case.
        for (const auto& [source, target, minutes] : connections) {
            network.connect(source, target, minutes);
            network.connect(target, source, minutes);
        }
    }

    const vector<string>& CampusMap::names() const {
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

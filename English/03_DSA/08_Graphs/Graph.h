// With inline we allow these definitions to be shared from the header across several files.

#ifndef COURSE_GRAPH_H
#define COURSE_GRAPH_H
// We use size_t to count elements and represent nonnegative positions.
#include <cstddef>
// We select the smallest value first in a priority queue using greater.
#include <functional>
// We use numeric_limits to check the largest allowed integer before adding.
#include <limits>
// We store a result that may be missing: optional holds a value or is empty.
#include <optional>
// We serve by arrival with queue or by importance with priority_queue.
#include <queue>
// We report when a value is invalid or a position does not exist.
#include <stdexcept>
// We use pair to keep two values together.
#include <utility>
// We store a collection that can grow using vector.
#include <vector>

namespace course {
    using namespace std;

    struct Edge {
        size_t destination;
        int weight;
    };

    class Graph {
        // Each vertex has a list of outgoing roads: an adjacency-list representation.
        vector<vector<Edge>> adjacency;

    public:
        explicit Graph(size_t vertices) : adjacency(vertices) {
        }
        size_t count() const {
            return adjacency.size();
        }
        const vector<Edge>& neighbors(size_t vertex) const {
            if (vertex >= count()) {
                throw out_of_range("That place does not exist in the graph");
            }
            return adjacency[vertex];
        }
        void connect(size_t source, size_t destination, int weight = 1) {
            if (weight < 0) {
                throw invalid_argument("Weight must be nonnegative");
            }
            // We check both places before storing the road.
            if (source >= count() || destination >= count()) {
                throw out_of_range("The source or destination does not exist");
            }
            adjacency[source].push_back({destination, weight});
        }
    };

    // BFS processes a queue in layers; marking on enqueue avoids repeated work in cycles.
    inline vector<size_t> bfs(const Graph& graph, size_t startIndex) {
        if (startIndex >= graph.count()) {
            throw out_of_range("The starting place does not exist");
        }
        vector<bool> visited(graph.count(), false);
        queue<size_t> pending;
        vector<size_t> order;
        visited[startIndex] = true;
        pending.push(startIndex);
        while (!pending.empty()) {
            auto current = pending.front();
            pending.pop();
            order.push_back(current);
            for (const auto& edge : graph.neighbors(current)) {
                if (!visited[edge.destination]) {
                    visited[edge.destination] = true; // Mark when enqueueing, before removal.
                    pending.push(edge.destination);
                }
            }
        }
        return order;
    }

    // DFS follows a branch and returns when it is exhausted; visited flags prevent looping.
    inline void visitDFS(const Graph& graph, size_t current, vector<bool>& visited,
                         vector<size_t>& order) {
        if (visited.size() != graph.count() || current >= visited.size()) {
            throw out_of_range("There is no slot for that place");
        }
        visited[current] = true;
        order.push_back(current);
        for (const auto& edge : graph.neighbors(current)) {
            if (!visited[edge.destination]) {
                visitDFS(graph, edge.destination, visited, order);
            }
        }
    }
    inline vector<size_t> dfs(const Graph& graph, size_t startIndex) {
        vector<bool> visited(graph.count(), false);
        vector<size_t> order;
        // We follow one branch and return to explore the others.
        visitDFS(graph, startIndex, visited, order);
        return order;
    }

    inline constexpr long long INFINITY_DISTANCE = numeric_limits<long long>::max();

    // Distances tell us the arrival cost; predecessors let us reconstruct the route.
    struct ShortestPaths {
        vector<long long> distances;
        vector<optional<size_t>> predecessors;
    };

    inline ShortestPaths shortestPaths(const Graph& graph, size_t source) {
        if (source >= graph.count()) {
            throw out_of_range("The starting place does not exist");
        }
        using Pending = pair<long long, size_t>;
        priority_queue<Pending, vector<Pending>, greater<Pending>> queuePending;
        ShortestPaths result{
            vector<long long>(graph.count(), INFINITY_DISTANCE),
            vector<optional<size_t>>(graph.count())
        };
        result.distances[source] = 0;
        queuePending.push({0, source});
        while (!queuePending.empty()) {
            // Each pending card holds two values: accumulated cost and place.
            const long long distance = queuePending.top().first;
            const size_t current = queuePending.top().second;
            queuePending.pop();
            if (distance != result.distances[current]) {
                continue;
            }
            for (const auto& edge : graph.neighbors(current)) {
                if (distance > INFINITY_DISTANCE - edge.weight) {
                    continue;
                }
                const long long candidate = distance + edge.weight;
                // Relaxation: improve the cost and remember the vertex we arrived from.
                if (candidate < result.distances[edge.destination]) {
                    result.distances[edge.destination] = candidate;
                    result.predecessors[edge.destination] = current;
                    queuePending.push({candidate, edge.destination});
                }
            }
        }
        return result;
    }

    // Earlier examples retain their distances-only API.
    inline vector<long long> dijkstra(const Graph& graph, size_t source) {
        return shortestPaths(graph, source).distances;
    }
} // namespace course

#endif

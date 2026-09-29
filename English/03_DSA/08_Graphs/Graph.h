#ifndef COURSE_GRAPH_H
#define COURSE_GRAPH_H
#include <cstddef>
#include <functional>
#include <limits>
#include <optional>
#include <queue>
#include <stdexcept>
#include <utility>
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
            return adjacency.at(vertex);
        }
        void connect(size_t source, size_t destination, int weight = 1) {
            if (weight < 0) {
                throw invalid_argument("Weight must be nonnegative");
            }
            (void)adjacency.at(destination); // Validate the destination before modifying the graph.
            adjacency.at(source).push_back({destination, weight});
        }
    };

    // BFS processes a queue in layers; marking on enqueue avoids repeated work in cycles.
    inline vector<size_t> bfs(const Graph& graph, size_t startIndex) {
        vector<bool> visited(graph.count(), false);
        queue<size_t> pending;
        vector<size_t> order;
        visited.at(startIndex) = true;
        pending.push(startIndex);
        while (!pending.empty()) {
            auto current = pending.front();
            pending.pop();
            order.push_back(current);
            for (const auto& edge : graph.neighbors(current)) {
                if (!visited.at(edge.destination)) {
                    visited.at(edge.destination) = true; // Mark when enqueueing, before removal.
                    pending.push(edge.destination);
                }
            }
        }
        return order;
    }

    // DFS follows a branch and returns when it is exhausted; visited flags prevent looping.
    inline void visitDFS(const Graph& graph, size_t current, vector<bool>& visited,
                         vector<size_t>& order) {
        visited.at(current) = true;
        order.push_back(current);
        for (const auto& edge : graph.neighbors(current)) {
            if (!visited.at(edge.destination)) {
                visitDFS(graph, edge.destination, visited, order);
            }
        }
    }
    inline vector<size_t> dfs(const Graph& graph, size_t startIndex) {
        vector<bool> visited(graph.count(), false);
        vector<size_t> order;
        // ponytail: recursive DFS for small examples; use an explicit stack for deep graphs.
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
        using Pending = pair<long long, size_t>;
        priority_queue<Pending, vector<Pending>, greater<Pending>> queuePending;
        ShortestPaths result{
            vector<long long>(graph.count(), INFINITY_DISTANCE),
            vector<optional<size_t>>(graph.count())
        };
        result.distances.at(source) = 0;
        queuePending.push({0, source});
        while (!queuePending.empty()) {
            auto [distance, current] = queuePending.top();
            queuePending.pop();
            if (distance != result.distances.at(current)) {
                continue;
            }
            for (const auto& edge : graph.neighbors(current)) {
                if (distance > INFINITY_DISTANCE - edge.weight) {
                    continue;
                }
                const long long candidate = distance + edge.weight;
                // Relaxation: improve the cost and remember the vertex we arrived from.
                if (candidate < result.distances.at(edge.destination)) {
                    result.distances.at(edge.destination) = candidate;
                    result.predecessors.at(edge.destination) = current;
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

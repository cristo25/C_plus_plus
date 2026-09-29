#ifndef COURSE_GRAPH_H
#define COURSE_GRAPH_H
#include <cstddef>
#include <functional>
#include <limits>
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

    inline vector<long long> dijkstra(const Graph& graph, size_t startIndex) {
        using Pending = pair<long long, size_t>; // Distance, vertex.
        priority_queue<Pending, vector<Pending>, greater<Pending>> queuePending;
        vector<long long> distances(graph.count(), INFINITY_DISTANCE);
        distances.at(startIndex) = 0;
        queuePending.push({0, startIndex});
        while (!queuePending.empty()) {
            auto [distance, current] = queuePending.top();
            queuePending.pop();
            if (distance != distances.at(current)) {
                continue; // Discard outdated entries.
            }
            for (const auto& edge : graph.neighbors(current)) {
                if (distance > INFINITY_DISTANCE - edge.weight) {
                    continue;
                }
                long long candidate = distance + edge.weight;
                if (candidate < distances.at(edge.destination)) {
                    distances.at(edge.destination) = candidate;
                    queuePending.push({candidate, edge.destination});
                }
            }
        }
        return distances;
    }
} // namespace course

#endif

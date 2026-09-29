#ifndef CURSO_GRAFO_H
#define CURSO_GRAFO_H
#include <cstddef>
#include <functional>
#include <limits>
#include <queue>
#include <stdexcept>
#include <utility>
#include <vector>

namespace curso {
    using namespace std;

    struct Arista {
        size_t destino;
        int peso;
    };

    class Grafo {
        vector<vector<Arista>> adyacencia;

    public:
        explicit Grafo(size_t vertices) : adyacencia(vertices) {
        }
        size_t cantidad() const {
            return adyacencia.size();
        }
        const vector<Arista>& vecinos(size_t vertice) const {
            return adyacencia.at(vertice);
        }
        void conectar(size_t origen, size_t destino, int peso = 1) {
            if (peso < 0) {
                throw invalid_argument("El peso debe ser no negativo");
            }
            (void)adyacencia.at(destino); // Valida el destino antes de modificar el grafo.
            adyacencia.at(origen).push_back({destino, peso});
        }
    };

    inline vector<size_t> bfs(const Grafo& grafo, size_t inicio) {
        vector<bool> visitado(grafo.cantidad(), false);
        queue<size_t> pendientes;
        vector<size_t> orden;
        visitado.at(inicio) = true;
        pendientes.push(inicio);
        while (!pendientes.empty()) {
            auto actual = pendientes.front();
            pendientes.pop();
            orden.push_back(actual);
            for (const auto& arista : grafo.vecinos(actual)) {
                if (!visitado.at(arista.destino)) {
                    visitado.at(arista.destino) = true; // Marca al encolar, no al retirar.
                    pendientes.push(arista.destino);
                }
            }
        }
        return orden;
    }

    inline void visitarDFS(const Grafo& grafo, size_t actual, vector<bool>& visitado,
                           vector<size_t>& orden) {
        visitado.at(actual) = true;
        orden.push_back(actual);
        for (const auto& arista : grafo.vecinos(actual)) {
            if (!visitado.at(arista.destino)) {
                visitarDFS(grafo, arista.destino, visitado, orden);
            }
        }
    }
    inline vector<size_t> dfs(const Grafo& grafo, size_t inicio) {
        vector<bool> visitado(grafo.cantidad(), false);
        vector<size_t> orden;
        // ponytail: DFS recursivo para ejemplos pequenos; pila explicita para gran profundidad.
        visitarDFS(grafo, inicio, visitado, orden);
        return orden;
    }

    inline constexpr long long INFINITO = numeric_limits<long long>::max();

    inline vector<long long> dijkstra(const Grafo& grafo, size_t inicio) {
        using Pendiente = pair<long long, size_t>; // Distancia, vertice.
        priority_queue<Pendiente, vector<Pendiente>, greater<Pendiente>> cola;
        vector<long long> distancias(grafo.cantidad(), INFINITO);
        distancias.at(inicio) = 0;
        cola.push({0, inicio});
        while (!cola.empty()) {
            auto [distancia, actual] = cola.top();
            cola.pop();
            if (distancia != distancias.at(actual)) {
                continue; // Descarta entradas antiguas.
            }
            for (const auto& arista : grafo.vecinos(actual)) {
                if (distancia > INFINITO - arista.peso) {
                    continue;
                }
                long long candidata = distancia + arista.peso;
                if (candidata < distancias.at(arista.destino)) {
                    distancias.at(arista.destino) = candidata;
                    cola.push({candidata, arista.destino});
                }
            }
        }
        return distancias;
    }
} // namespace curso

#endif

#ifndef CURSO_GRAFO_H
#define CURSO_GRAFO_H
#include <cstddef>
#include <functional>
#include <limits>
#include <optional>
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
        // Cada vértice tiene una lista de carreteras salientes: representación por adyacencia.
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

    // BFS procesa una cola por niveles; marcar al encolar evita trabajo repetido en ciclos.
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

    // DFS baja por una rama y vuelve al agotarla; visitado impide regresar en círculos.
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

    // Las distancias dicen cuánto cuesta llegar; los anteriores permiten reconstruir la ruta.
    struct CaminosMinimos {
        vector<long long> distancias;
        vector<optional<size_t>> anteriores;
    };

    inline CaminosMinimos caminosMinimos(const Grafo& grafo, size_t origen) {
        using Pendiente = pair<long long, size_t>;
        priority_queue<Pendiente, vector<Pendiente>, greater<Pendiente>> cola;
        CaminosMinimos resultado{
            vector<long long>(grafo.cantidad(), INFINITO),
            vector<optional<size_t>>(grafo.cantidad())
        };
        resultado.distancias.at(origen) = 0;
        cola.push({0, origen});
        while (!cola.empty()) {
            auto [distancia, actual] = cola.top();
            cola.pop();
            if (distancia != resultado.distancias.at(actual)) {
                continue;
            }
            for (const auto& arista : grafo.vecinos(actual)) {
                if (distancia > INFINITO - arista.peso) {
                    continue;
                }
                const long long candidato = distancia + arista.peso;
                // Relajamos: mejora el costo y guardamos desde qué vértice llegamos.
                if (candidato < resultado.distancias.at(arista.destino)) {
                    resultado.distancias.at(arista.destino) = candidato;
                    resultado.anteriores.at(arista.destino) = actual;
                    cola.push({candidato, arista.destino});
                }
            }
        }
        return resultado;
    }

    // Los ejemplos anteriores conservan la misma API de solo distancias.
    inline vector<long long> dijkstra(const Grafo& grafo, size_t origen) {
        return caminosMinimos(grafo, origen).distancias;
    }
} // namespace curso

#endif

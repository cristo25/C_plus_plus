// Con inline permitimos compartir estas definiciones desde el header entre varios archivos.

#ifndef CURSO_GRAFO_H
#define CURSO_GRAFO_H
// Usamos size_t para contar elementos y representar posiciones no negativas.
#include <cstddef>
// Elegimos primero el menor valor de una cola de prioridad mediante greater.
#include <functional>
// Consultamos con numeric_limits el mayor entero permitido antes de sumar.
#include <limits>
// Guardamos un resultado que puede faltar: optional tiene un valor o está vacío.
#include <optional>
// Atendemos por llegada con queue o por importancia con priority_queue.
#include <queue>
// Avisamos cuando un dato no es válido o una posición no existe.
#include <stdexcept>
// Usamos pair para guardar dos datos juntos.
#include <utility>
// Guardamos una colección que puede crecer con vector.
#include <vector>

namespace curso {
    using namespace std;

    struct Arista {
        size_t destino;
        int peso;
    };

    class Grafo {
        // Guardamos para cada lugar una lista de los caminos que salen de él; esa es su lista de
        // vecinos.
        vector<vector<Arista>> adyacencia;

    public:
        explicit Grafo(size_t vertices) : adyacencia(vertices) {
        }
        size_t cantidad() const {
            return adyacencia.size();
        }
        const vector<Arista>& vecinos(size_t vertice) const {
            if (vertice >= cantidad()) {
                throw out_of_range("Ese lugar no existe en el grafo");
            }
            return adyacencia[vertice];
        }
        void conectar(size_t origen, size_t destino, int peso = 1) {
            if (peso < 0) {
                throw invalid_argument("El peso debe ser no negativo");
            }
            // Revisamos ambos lugares antes de guardar el camino.
            if (origen >= cantidad() || destino >= cantidad()) {
                throw out_of_range("El origen o el destino no existe");
            }
            adyacencia[origen].push_back({destino, peso});
        }
    };

    // BFS procesa una cola por niveles; marcar al encolar evita trabajo repetido en ciclos.
    inline vector<size_t> bfs(const Grafo& grafo, size_t inicio) {
        if (inicio >= grafo.cantidad()) {
            throw out_of_range("El lugar inicial no existe");
        }
        vector<bool> visitado(grafo.cantidad(), false);
        queue<size_t> pendientes;
        vector<size_t> orden;
        visitado[inicio] = true;
        pendientes.push(inicio);
        while (!pendientes.empty()) {
            auto actual = pendientes.front();
            pendientes.pop();
            orden.push_back(actual);
            for (const auto& arista : grafo.vecinos(actual)) {
                if (!visitado[arista.destino]) {
                    visitado[arista.destino] = true; // Marca al encolar, no al retirar.
                    pendientes.push(arista.destino);
                }
            }
        }
        return orden;
    }

    // DFS baja por una rama y vuelve al agotarla; visitado impide regresar en círculos.
    inline void visitarDFS(const Grafo& grafo, size_t actual, vector<bool>& visitado,
                           vector<size_t>& orden) {
        if (visitado.size() != grafo.cantidad() || actual >= visitado.size()) {
            throw out_of_range("No hay una casilla para ese lugar");
        }
        visitado[actual] = true;
        orden.push_back(actual);
        for (const auto& arista : grafo.vecinos(actual)) {
            if (!visitado[arista.destino]) {
                visitarDFS(grafo, arista.destino, visitado, orden);
            }
        }
    }
    inline vector<size_t> dfs(const Grafo& grafo, size_t inicio) {
        vector<bool> visitado(grafo.cantidad(), false);
        vector<size_t> orden;
        // Seguimos una rama y regresamos para explorar las demás.
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
        if (origen >= grafo.cantidad()) {
            throw out_of_range("El lugar inicial no existe");
        }
        using Pendiente = pair<long long, size_t>;
        priority_queue<Pendiente, vector<Pendiente>, greater<Pendiente>> cola;
        CaminosMinimos resultado{
            vector<long long>(grafo.cantidad(), INFINITO),
            vector<optional<size_t>>(grafo.cantidad())
        };
        resultado.distancias[origen] = 0;
        cola.push({0, origen});
        while (!cola.empty()) {
            // Cada ficha pendiente tiene dos datos: costo acumulado y lugar.
            const long long distancia = cola.top().first;
            const size_t actual = cola.top().second;
            cola.pop();
            if (distancia != resultado.distancias[actual]) {
                continue;
            }
            for (const auto& arista : grafo.vecinos(actual)) {
                if (distancia > INFINITO - arista.peso) {
                    continue;
                }
                const long long candidato = distancia + arista.peso;
                // Encontramos un viaje más barato: cambiamos el costo y recordamos desde dónde
                // llegamos.
                if (candidato < resultado.distancias[arista.destino]) {
                    resultado.distancias[arista.destino] = candidato;
                    resultado.anteriores[arista.destino] = actual;
                    cola.push({candidato, arista.destino});
                }
            }
        }
        return resultado;
    }

    // Con esta función devolvemos solo los costos, como en los ejemplos que no necesitan mostrar la
    // ruta.
    inline vector<long long> dijkstra(const Grafo& grafo, size_t origen) {
        return caminosMinimos(grafo, origen).distancias;
    }
} // namespace curso

#endif

# Dijkstra: caminos de menor costo

## Qué aprenderás

Dijkstra obtiene distancias mínimas con pesos no negativos. Usa una cola de prioridad de menor costo, mejora distancias y descarta entradas obsoletas. `INFINITO` indica un vértice inalcanzable. Esta versión permite entradas repetidas en la cola: tiempo O((V + E) log(E + 2)) y memoria O(V + E). No devuelve las rutas, solo sus costos.

## Analogía

Un repartidor compara el costo total de las rutas y siempre considera primero la alternativa más barata disponible.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: costos `0, 3, 1, 4` para los vértices 0 a 3; el 4 muestra `sin ruta`.

## Practica

Agrega un vector de predecesores para reconstruir una ruta. Para pesos negativos investiga Bellman-Ford en una ampliación posterior.

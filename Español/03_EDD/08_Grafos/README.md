# Grafos

Estudia representación, recorridos y costos mínimos. BFS y DFS no usan los pesos; Dijkstra sí. El integrador compara ambos recorridos y calcula costo mínimo 4 del vértice 0 al 3. Los headers contienen funciones `inline` para poder reutilizarlas sin definiciones duplicadas al enlazar.

## Orden de estudio

1. [Representación](01_Representacion/README.md)
2. [BFS](02_BFS/README.md)
3. [DFS](03_DFS/README.md)
4. [Dijkstra](04_Dijkstra/README.md)

Después, lee y ejecuta el `main.cpp` de **esta carpeta**: reúne lo aprendido en las subcarpetas.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Cada subcarpeta tiene su propio programa. Compila un ejemplo a la vez: todos tienen su propia función `main`.

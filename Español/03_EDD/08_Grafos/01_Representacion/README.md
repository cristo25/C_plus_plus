# Representar grafos

## Qué aprenderás

Un grafo contiene vértices y aristas. La lista de adyacencia guarda los vecinos de cada vértice y ocupa O(V + E); una matriz de adyacencia ocupa O(V²). `Grafo` representa aristas dirigidas con pesos no negativos. Para una conexión no dirigida agrega ambas direcciones.

## Analogía

Las ciudades son vértices; las carreteras son aristas; el costo de recorrer una carretera es su peso.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `1 -> 0 costo 5` y `1 -> 2 costo 2`.

## Practica

Dibuja el mapa y agrega un vértice aislado. Compara listas y matrices en un grafo con pocas aristas.

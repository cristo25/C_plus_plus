# BFS: búsqueda en anchura

## Qué aprenderás

BFS usa una cola y visita por niveles. Marca cada vértice al encolarlo para no repetirlo cuando hay ciclos. Recorre solo los vértices alcanzables desde el inicio. En grafos sin pesos, los niveles describen distancias mínimas en número de aristas. Tiempo O(V + E), memoria auxiliar O(V).

## Analogía

Exploras una ciudad por anillos: primero los vecinos cercanos, después sus vecinos.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `0 1 2 3`. El vértice 4 está aislado y no aparece.

## Practica

Agrega una arista hacia 4. Explica cómo cambiaría el orden al cambiar el orden de los vecinos.

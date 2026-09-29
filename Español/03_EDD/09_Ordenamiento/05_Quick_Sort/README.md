# Quick sort

## Qué aprenderás

Elige un pivote, coloca los menores a un lado y ordena las particiones. Suele costar O(n log n), pero esta elección de pivote llega a O(n²) con entradas ordenadas o iguales. La pila recursiva puede crecer hasta O(n). No es estable. Lee su función en `../Ordenamientos.h`.

## Analogía

Un pivote divide una fila: los menores pasan a la izquierda y los demás a la derecha; repites en cada grupo.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `-1 0 3 3 5`.

## Practica

Traza el pivote en 4, 1, 3, 2. Prueba datos ordenados y explica por qué esta versión se desequilibra.

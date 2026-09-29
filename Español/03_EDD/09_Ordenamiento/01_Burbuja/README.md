# Burbuja

## Qué aprenderás

Compara vecinos y los intercambia si están invertidos. Cada pasada coloca el mayor restante al final. Tiempo O(n²) en promedio y peor caso; O(n) si ya está ordenado gracias al indicador de cambios. Memoria adicional O(1). Es estable. Lee su función en `../Ordenamientos.h`.

## Analogía

Las burbujas grandes suben al extremo; cada pasada lleva el mayor número al final.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `-1 0 3 3 5`.

## Practica

Dibuja cada pasada para los datos 4, 2, 3, 1.

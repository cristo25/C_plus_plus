# Inserción

## Qué aprenderás

Mantiene una zona izquierda ordenada e inserta cada dato nuevo desplazando los mayores. Tiempo O(n²) en promedio y peor caso, O(n) en datos ya ordenados; memoria adicional O(1). Es estable. Lee su función en `../Ordenamientos.h`.

## Analogía

Ordenas una mano de cartas colocando cada carta nueva en su lugar entre las anteriores.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `-1 0 3 3 5`.

## Practica

Traza los desplazamientos cuando insertas el 2 en 1, 3, 4.

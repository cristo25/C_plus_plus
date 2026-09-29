# Búsqueda binaria

## Qué aprenderás

Requiere un vector ordenado de menor a mayor. Cada comparación descarta la mitad del rango; tiempo O(log n), espacio auxiliar O(1). Ordenar primero tiene su propio costo: no es gratis. Esta versión devuelve la primera coincidencia.

## Analogía

Abres una guía ordenada por la mitad y decides qué mitad conserva el número que buscas.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `Indice: 1`. La alternativa estándar es `lower_bound`; `binary_search` solo indica si existe.

## Practica

Dibuja los rangos al buscar 8. Explica por qué no debes usarla directamente con 8, 1, 3.

# Cola de prioridad y heap

## Qué aprenderás

`priority_queue` utiliza un heap (montículo). Por defecto coloca el mayor arriba; con `greater<int>` coloca el menor. Consultar `top` cuesta O(1); insertar y retirar, O(log n). No conserva el orden de llegada entre prioridades iguales.

## Analogía

En urgencias se atiende por prioridad; la gravedad decide el siguiente turno.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `Mayor prioridad: 9` y `Menor costo: 2`.

## Practica

Retira todos los valores de ambas colas. Explica por qué un heap no equivale a un vector completamente ordenado.

# DFS: búsqueda en profundidad

## Qué aprenderás

DFS sigue una rama hasta que no puede avanzar y luego regresa. Puede usar recursión o una pila explícita. Los visitados evitan ciclos. Tiempo O(V + E), memoria auxiliar O(V). El orden depende del orden de los vecinos.

## Analogía

Exploras un laberinto siguiendo un pasillo hasta el fondo y retrocedes para probar los demás.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `0 1 3 2`. El ciclo hacia 0 no provoca recursión infinita.

## Practica

Compara este recorrido con BFS usando el mismo dibujo.

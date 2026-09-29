# Lista doblemente ligada

## Qué aprenderás

Cada nodo conoce al anterior y al siguiente. Guardar inicio y fin permite agregar al final en O(1) y recorrer en ambos sentidos. Buscar un valor sigue siendo O(n); borrar un nodo ya localizado requiere ajustar ambos enlaces.

## Analogía

Los vagones de un tren están enganchados por delante y por detrás; puedes caminar en ambos sentidos.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `30 20 10`.

## Practica

Dibuja los dos enlaces que cambian al borrar un nodo del medio.

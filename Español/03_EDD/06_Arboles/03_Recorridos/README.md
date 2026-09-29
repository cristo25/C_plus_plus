# Recorridos de un árbol

## Qué aprenderás

Preorden visita raíz, izquierda, derecha. Inorden visita izquierda, raíz, derecha. Postorden visita izquierda, derecha, raíz. En un ABB, inorden produce valores ordenados. Los recorridos visitan todos los nodos: O(n), con O(h) de pila recursiva más el vector de salida.

## Analogía

Recorres una casa: puedes registrar el cuarto antes de visitar sus anexos, entre ambos anexos o al terminar de visitarlos.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida, en orden: preorden `4 2 1 3 6 5 7`, inorden `1 2 3 4 5 6 7` y postorden `1 3 2 5 7 6 4`.

## Practica

Dibuja el árbol y reproduce cada recorrido con flechas antes de ejecutarlo.

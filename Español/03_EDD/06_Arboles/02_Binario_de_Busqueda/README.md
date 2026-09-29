# Árbol binario de búsqueda (ABB)

## Qué aprenderás

En este ABB los menores van a la izquierda y los mayores a la derecha; rechazamos duplicados. Inserción, consulta y eliminación cuestan O(h), donde h es la altura. Al borrar un nodo con dos hijos, lo sustituimos por el menor del subárbol derecho. Un ABB sin balancear puede degenerar en una cadena.

## Analogía

Una guía de números: cada nodo indica si seguir hacia los menores o hacia los mayores.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `1 3 6 10`.

## Practica

Inserta números ya ordenados y dibuja el árbol. Compara su altura con otro orden de inserción.

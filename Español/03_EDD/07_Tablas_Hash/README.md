# Tablas hash con unordered_map

## Qué aprenderás

`unordered_map` asocia claves únicas con valores mediante una función hash. Buscar e insertar cuestan O(1) en promedio y O(n) en el peor caso. La biblioteca administra las colisiones; el orden de recorrido no está garantizado. `operator[]` puede insertar: usa `find` para solo consultar.

## Analogía

Un recepcionista transforma una clave en el número de un casillero. Si varias claves coinciden, debe distinguir sus fichas.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `Ana`.

## Practica

Intenta insertar dos veces la misma clave con `emplace` y revisa el valor booleano del resultado.

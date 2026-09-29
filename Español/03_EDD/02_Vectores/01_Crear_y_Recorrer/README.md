# Crear y recorrer un vector

## Qué aprenderás

`vector` es un arreglo contiguo cuyo tamaño puede cambiar. `size()` es la cantidad de elementos; `capacity()` es el espacio reservado. `push_back` cuesta O(1) amortizado, aunque una realocación individual cuesta O(n).

## Analogía

Es un cajón extensible: al llenarse, puede mudarse a un cajón mayor. Sus secciones siguen numeradas desde cero.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `Suma: 60`.

## Practica

Usa `reserve(10)` y comprueba que cambia la capacidad, pero no agrega elementos.

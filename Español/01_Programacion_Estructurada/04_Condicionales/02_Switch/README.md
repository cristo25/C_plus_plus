# Elegir con switch

## Qué aprenderás

`switch` elige entre valores concretos de un entero, carácter o enumeración. `break` termina un caso; `default` atiende valores desconocidos.

## Analogía

Un menú de restaurante tiene opciones numeradas. Cada número lleva a una preparación.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `Cafe`. Aquí `return` termina el caso y la función; por eso no hace falta `break`.

## Practica

Agrega una tercera bebida. Prueba también la opción 0.

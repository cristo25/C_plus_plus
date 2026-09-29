# Referencias y paso de parámetros

## Qué aprenderás

`int&` es un alias del dato original. `const string&` permite consultar una cadena sin copiarla ni modificarla. Una referencia válida se inicializa al declararse.

## Analogía

Una referencia es una segunda etiqueta en la misma caja; no es otra caja.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `5`.

## Practica

Cambia el parámetro a `int numero` y observa por qué falla la comprobación.

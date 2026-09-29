# Recursión

## Qué aprenderás

Una función recursiva se llama a sí misma con un problema menor. El caso base detiene las llamadas. Sin caso base o sin avance, la pila de llamadas puede agotarse.

## Analogía

Abres una caja que contiene otra más pequeña, hasta llegar a una caja vacía.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `120`. Limitamos a 12 para que el resultado quepa en los `int` de 32 bits habituales. `throw` señala una entrada inválida; `try/catch` permite comprobar ese rechazo.

## Practica

Dibuja las llamadas de `factorial(3)` y su regreso. Después escribe la versión con `for`.

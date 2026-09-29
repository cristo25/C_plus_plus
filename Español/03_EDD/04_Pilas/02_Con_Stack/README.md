# El adaptador stack

## Qué aprenderás

`stack` ofrece solo las operaciones de pila: `push`, `top`, `pop`, `size`, `empty`. `pop` elimina pero no devuelve el valor; consúltalo antes con `top`. El adaptador restringe las operaciones del contenedor subyacente.

## Analogía

Una caja de platos con una sola abertura arriba: no puedes tomar el plato de en medio.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `Deshacer: Borrar`.

## Practica

Simula dos operaciones y dos acciones de deshacer; protege también el tercer intento.

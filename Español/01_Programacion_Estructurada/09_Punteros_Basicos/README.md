# Punteros: dirección y contenido

## Qué aprenderás

`&dato` obtiene una dirección; `int*` guarda una dirección de un entero y `*puntero` accede al contenido. `nullptr` representa la ausencia de un destino. El dato debe seguir vivo mientras lo usas mediante un puntero. Todavía no necesitas `new`.

## Analogía

La variable es una casa; el puntero es un papel con su dirección. `&` anota la dirección y `*` visita la casa. Una dirección no garantiza que la casa siga existiendo.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `Contenido: 25`. Nunca desreferencies `nullptr` ni uses la dirección de una variable que ya terminó su vida.

## Practica

Crea dos punteros al mismo entero y comprueba que ambos observan los cambios.

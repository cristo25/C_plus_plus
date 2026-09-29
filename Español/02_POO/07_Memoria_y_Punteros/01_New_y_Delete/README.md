# Memoria dinámica manual

## Qué aprenderás

`new` construye un objeto dinámico y `delete` lo destruye. Debe existir exactamente un propietario responsable de liberarlo. Para arreglos creados con `new[]` corresponde `delete[]`. En código habitual usa objetos por valor, `vector` o punteros inteligentes.

## Analogía

Alquilas un casillero: conservas la dirección y debes devolverlo una vez. Devolverlo dos veces o visitarlo después es un error.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `42`. Este ejemplo aísla el mecanismo; una salida prematura entre `new` y `delete` podría provocar una fuga. En la siguiente lección usamos RAII.

## Practica

Dibuja cuándo empieza y termina la vida del entero. No lo leas después de `delete`.

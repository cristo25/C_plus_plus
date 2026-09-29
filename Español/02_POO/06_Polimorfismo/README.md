# Polimorfismo y clases abstractas

## Qué aprenderás

Un método `virtual` permite elegir la implementación según el objeto real. `= 0` define una operación abstracta y `override` verifica que la redefiniste correctamente. Una base polimórfica necesita destructor virtual si se destruyen derivados mediante ella.

## Analogía

El botón «hacer sonido» funciona con varios instrumentos; cada instrumento decide qué sonido producir.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `Cuerdas` y `Percusion`.

## Practica

Agrega `Flauta` y úsala con la misma función `tocar`. No cambies esa función.

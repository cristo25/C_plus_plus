# Vectores de objetos

## Qué aprenderás

Un vector puede guardar objetos del mismo tipo. Un `struct` tiene miembros públicos por defecto; en una `class` son privados por defecto. `const auto&` permite recorrer sin copiar ni modificar.

## Analogía

El cajón ahora guarda fichas completas: cada ficha tiene un nombre y una nota.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `Ana: 9`, `Luis: 8` y `Eva: 10`.

## Practica

Calcula el promedio del grupo. Define qué hacer si el vector está vacío.

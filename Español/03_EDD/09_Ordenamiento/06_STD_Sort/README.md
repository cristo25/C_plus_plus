# Ordenar con la biblioteca estándar

## Qué aprenderás

`sort` ofrece O(n log n) comparaciones en el peor caso y no garantiza estabilidad. `stable_sort` conserva el orden de elementos equivalentes. El comparador debe expresar un orden estricto: usa `<`, no `<=`. Aprende los algoritmos manuales y usa la biblioteca para tareas habituales.

## Analogía

Encargas ordenar el cajón a una herramienta ya probada, indicándole cómo comparar sus objetos.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `Ana: 8`, `Luis: 8` y `Eva: 9`. La lambda `[](...) { ... }` es una función pequeña escrita donde se utiliza.

## Practica

Ordena por nombre. Después ordena por nota descendente conservando el orden de los empates.

# Integrador: procesar tareas y consultar rutas

## Qué aprenderás

Combina vector, lista, pila, cola, cola de prioridad, ABB, tabla hash, grafo, ordenamiento y búsqueda. Reutiliza los headers de EDD. La cola define el orden de trabajo; la lista conserva el historial y la pila permite consultar qué se desharía primero.

## Analogía

Un taller recibe órdenes, las atiende, conserva un historial, organiza prioridades y consulta un mapa para las entregas.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: procesa `Practicar`, `Leer`, `Compilar`; la última tarea es `Compilar` y el costo mínimo de entrega es `2`.

Los `assert` del programa comprueban su comportamiento. Si alguno falla, la ejecución se detiene; no compiles con `-DNDEBUG` al estudiar estos ejemplos.

## Practica

Agrega una cuarta tarea y actualiza las comprobaciones. Explica qué estructura elegirías si solo necesitaras guardar el historial; este programa reúne varias para practicar, no porque todas sean necesarias para ese requisito.

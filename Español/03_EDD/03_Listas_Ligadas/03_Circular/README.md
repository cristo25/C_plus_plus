# Lista circular

## Qué aprenderás

El último nodo apunta al primero. Debes detenerte al volver al inicio; esperar `nullptr` causaría un ciclo infinito. La inserción al final cuesta O(1); buscar y eliminar por valor cuestan O(n). Esta variante es simplemente ligada y circular.

## Analogía

Una rueda de turnos: después de la última persona regresas a la primera.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `1 3`. El recorrido hace una vuelta completa.

## Practica

Dibuja el caso de un solo nodo: apunta a sí mismo. Explica por qué necesita un caso especial al eliminarlo.

# Merge sort

## Qué aprenderás

Divide por mitades, ordena cada mitad y las mezcla. Tiempo O(n log n); usa O(n) de memoria auxiliar y O(log n) de llamadas. Es estable porque, ante empates, toma primero el elemento de la izquierda. Lee su función en `../Ordenamientos.h`.

## Analogía

Divides hojas entre dos ayudantes y luego reúnes sus montones ordenados tomando la menor hoja disponible.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `-1 0 3 3 5`.

## Practica

Dibuja las divisiones y mezclas de seis números. Observa que el final del rango se excluye.

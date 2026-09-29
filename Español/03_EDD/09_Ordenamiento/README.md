# Algoritmos de ordenamiento

Estudia cada algoritmo con la misma entrada y compara trabajo, memoria y estabilidad. Estable significa conservar el orden original de elementos con la misma clave. El integrador verifica cinco algoritmos contra `sort`, incluyendo vector vacío, repetidos, negativos y datos ya ordenados. Los punteros a funciones permiten repetir la misma comprobación.

## Orden de estudio

1. [Burbuja](01_Burbuja/README.md)
2. [Selección](02_Seleccion/README.md)
3. [Inserción](03_Insercion/README.md)
4. [Merge sort](04_Merge_Sort/README.md)
5. [Quick sort](05_Quick_Sort/README.md)
6. [Biblioteca estándar](06_STD_Sort/README.md)

Después, lee y ejecuta el `main.cpp` de **esta carpeta**: reúne lo aprendido en las subcarpetas.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Cada subcarpeta tiene su propio programa. Compila un ejemplo a la vez: todos tienen su propia función `main`.

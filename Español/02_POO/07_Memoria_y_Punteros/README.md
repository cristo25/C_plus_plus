# Memoria y punteros en POO

Relaciona propiedad con vida del objeto. El integrador administra un alumno con `unique_ptr` y lo consulta mediante un puntero que no es propietario.

## Orden de estudio

1. [New y delete](01_New_y_Delete/main.cpp)
2. [Unique ptr](02_Unique_Ptr/main.cpp)

Después, lee y ejecuta el `main.cpp` de **esta carpeta**: reúne lo aprendido en las subcarpetas.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Cada subcarpeta tiene su propio programa. Compila un ejemplo a la vez: todos tienen su propia función `main`.


Para combinar estos conceptos, sigue la [ruta de arreglos, vistas y clases con nodos](../../03_EDD/13_Combinacion_de_Conceptos/README.md). Allí se explica qué punteros siguen siendo válidos al crecer un vector y cuáles se invalidan.

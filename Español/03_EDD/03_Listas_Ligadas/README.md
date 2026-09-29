# Listas ligadas

Las tres implementaciones guardan enteros para concentrarnos en los enlaces y la propiedad de los nodos. Usa `new/delete` aquí para estudiar el mecanismo; los contenedores estándar ya resuelven su gestión en aplicaciones comunes. El integrador usa los tres headers y elimina el dato 20 de cada lista. Cambia los datos y compara los recorridos. Después prueba eliminar el inicio, el final y el único nodo.

## Orden de estudio

1. [Simplemente ligada](01_Simplemente_Ligada/main.cpp)
2. [Doblemente ligada](02_Doblemente_Ligada/main.cpp)
3. [Circular](03_Circular/main.cpp)

Después, lee y ejecuta el `main.cpp` de **esta carpeta**: reúne lo aprendido en las subcarpetas.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Cada subcarpeta tiene su propio programa. Compila un ejemplo a la vez: todos tienen su propia función `main`.

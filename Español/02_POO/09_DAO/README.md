# DAO: separar el acceso a datos

Estudia CRUD en memoria y después persistencia. El integrador combina ambas operaciones usando un flujo en memoria para comprobar el formato sin crear archivos. Los headers de este bloque contienen definiciones dentro de la clase, implícitamente `inline`. El DAO permite consultas lineales y limita la carga a 10 000 registros; una base de datos será otro paso si hace falta.

## Orden de estudio

1. [DAO en memoria](01_DAO_en_Memoria/README.md)
2. [DAO en archivo](02_DAO_en_Archivo/README.md)

Después, lee y ejecuta el `main.cpp` de **esta carpeta**: reúne lo aprendido en las subcarpetas.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Cada subcarpeta tiene su propio programa. Compila un ejemplo a la vez: todos tienen su propia función `main`.

La creación y la carga respetan el mismo límite de 10 000 libros.

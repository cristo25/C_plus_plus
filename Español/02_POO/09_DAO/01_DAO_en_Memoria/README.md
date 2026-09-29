# DAO en memoria y CRUD

## Qué aprenderás

DAO significa Data Access Object: es un patrón de acceso a datos, no un paradigma. `LibroDAO` concentra crear, consultar, actualizar y eliminar (CRUD). La aplicación usa esas operaciones sin manipular el contenedor. Por ahora `vector` es una colección que crece; lo estudiaremos en EDD.

## Analogía

El bibliotecario (DAO) conoce dónde están los libros; tú le pides uno por su ficha sin revisar cada estante.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `C++ paso a paso`. Los datos desaparecen al terminar. El puntero devuelto por `buscar` es una consulta temporal: no lo conserves tras crear, eliminar o cargar datos.

## Practica

Agrega dos libros y lista `dao.todos()`. Comprueba que actualizar un ID inexistente devuelve `false`.

La creación y la carga respetan el mismo límite de 10 000 libros.

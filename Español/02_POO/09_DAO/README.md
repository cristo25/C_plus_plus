# DAO: separar el acceso a datos

## DAO en memoria y CRUD

Vamos a reunir en LibroDAO las tareas de guardar, buscar, cambiar y eliminar libros. Podemos imaginar un encargado del catálogo: le pedimos un libro por su id, que es un número que lo identifica. DAO es el nombre habitual de una clase dedicada al acceso a datos. Aquí guardamos los libros en un vector, por lo que desaparecen al terminar el programa. buscar presta un puntero al libro, o devuelve nullptr si no existe. Antes de leerlo comprobamos el resultado; después de cambiar el catálogo volvemos a buscarlo, porque el vector puede mover sus libros.

[Programa comentado](01_DAO_en_Memoria/main.cpp).

## Persistir un DAO en un archivo

Vamos a guardar el catálogo en un archivo para recuperarlo después. Primero pedimos al DAO que escriba sus libros y luego que los lea en otro catálogo. En cada ejecución volvemos a escribir el archivo con el catálogo actual. Si encontramos datos incorrectos, avisamos sin sustituir el catálogo por una lectura incompleta. Para probar ese caso usamos istringstream, de <sstream>: permite leer un texto guardado en memoria como si llegara de un archivo. Así podemos ensayar una entrada dañada sin dañar el archivo real.

Podemos imaginar el archivo como una libreta. Primero anotamos cuántos libros hay; después dedicamos una línea al número de cada libro y otra a su título. Si guardamos un libro con id 7, la libreta queda así:

```text
1
7
C++ paso a paso
```

Al leer, usamos esas líneas para llenar otro catálogo. Como el título ocupa toda su línea, puede contener espacios y comillas.

[Programa comentado](02_DAO_en_Archivo/main.cpp).

## DAO: separar el acceso a datos

Vamos a recorrer todo el trabajo del catálogo: crear libros, cambiar un título, eliminar un libro y recuperar lo guardado. Aquí usamos stringstream, de <sstream>, como un cuaderno temporal en memoria: podemos escribir en él y volver a leer sin crear un archivo en disco. Después probamos una lectura con ids repetidos. La regla es sencilla: si no podemos recuperar todos los datos correctamente, conservamos el catálogo que ya teníamos.

[Programa comentado](main.cpp).

**Práctica.** Realiza un programa integrador para administrar y recuperar libros.

- Crear tres libros, cambiar un título y eliminar uno.
- Guardar el resultado y cargarlo en un segundo catálogo.
- Comparar los libros recuperados con los originales.
- Probar un id duplicado y un archivo incompleto.
- Conservar los datos anteriores si falla la carga.

[Volvemos a la guía general](../../README.md).

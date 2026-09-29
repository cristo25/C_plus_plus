# Persistir un DAO en un archivo

## Qué aprenderás

`guardar` serializa una instantánea y `cargar` la valida antes de reemplazar los datos en memoria. `quoted` conserva espacios y comillas. Cada instantánea comienza con su cantidad de libros. Este ejemplo agrega instantáneas al archivo y recupera la última completa.

## Analogía

El bibliotecario toma una fotografía del catálogo al cerrar. Al abrir consulta la fotografía más reciente para recuperar el estado.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `C++ con ejemplos`. Agrega una instantánea a `libros_demo.txt` por ejecución. El lector avisa si encuentra datos dañados; no los descarta silenciosamente. Las instantáneas admiten hasta 10 000 libros.

## Practica

Guarda un título con comillas. Modifica una copia del archivo para duplicar un ID y comprueba el rechazo.

La creación y la carga respetan el mismo límite de 10 000 libros.

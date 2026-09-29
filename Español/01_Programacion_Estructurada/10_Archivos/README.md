# Leer y escribir archivos

## Qué aprenderás

`ofstream` escribe y `ifstream` lee. Comprueba apertura, escritura y lectura. Los objetos cierran los archivos al salir de su bloque. `ios::app` agrega contenido al final.

## Analogía

La memoria es un pizarrón que se borra al terminar; un archivo es un cuaderno que conserva tus anotaciones.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Crea o amplía `notas_demo.txt` en la carpeta desde la que ejecutas el programa. Cada ejecución agrega una línea `Estudiar C++`.

## Practica

Agrega otra nota y vuelve a leer el archivo. Explica qué ocurriría usando `ios::trunc`.

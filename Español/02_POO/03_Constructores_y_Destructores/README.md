# Constructores, destructores y RAII

## Qué aprenderás

El constructor establece un estado inicial válido y el destructor corre al terminar la vida del objeto. RAII vincula la vida de un recurso a la de un objeto; `string`, archivos y punteros inteligentes ya lo hacen.

## Analogía

Al abrir una tienda colocas el letrero; al cerrar recoges lo que administraba la tienda.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida en orden: `Entra Ana`, `Sale Ana`, `Sesion terminada`. No escribas destructores vacíos: este imprime para que puedas observar el momento.

## Practica

Construye dos sesiones en el mismo bloque y observa el orden inverso de destrucción.

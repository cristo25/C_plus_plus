# Cadenas con string

## Qué aprenderás

`string` administra una secuencia de caracteres. Puedes concatenar, consultar el tamaño, buscar y extraer fragmentos. Comprueba `string::npos` antes de usar un resultado de búsqueda.

## Analogía

Una cadena es un collar: cada carácter es una cuenta; puedes unir collares o tomar un tramo.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `Hola, Ana`. `size()` cuenta bytes; letras con acentos pueden ocupar más de un byte en UTF-8.

## Practica

Busca una palabra que no exista y evita llamar `substr` con `npos`.

El fragmento encontrado se muestra en otra línea: `Ana`.

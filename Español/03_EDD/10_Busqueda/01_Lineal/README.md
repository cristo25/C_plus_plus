# Búsqueda lineal

## Qué aprenderás

Revisa desde el inicio hasta encontrar el valor. No necesita orden previo. Tiempo O(n); espacio auxiliar O(1). `optional` contiene una posición o `nullopt` si no existe. Comprueba que tiene valor antes de usar `*resultado`. La posición 0 también es un resultado válido.

## Analogía

Buscas una llave revisando cada compartimento del cajón.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `Indice: 1`. En aplicaciones puedes usar `find` en lugar de reescribir el recorrido.

## Practica

Busca el primer elemento, el último y uno inexistente.

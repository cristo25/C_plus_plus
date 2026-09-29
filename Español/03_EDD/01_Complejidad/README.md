# Complejidad: tiempo y espacio

## Qué aprenderás

Big O describe cómo crece el trabajo con el tamaño de la entrada, no los segundos exactos. Acceder por índice es O(1); recorrer n elementos es O(n); reducir el problema a la mitad repetidamente requiere O(log n) pasos. También cuenta la memoria adicional.

## Analogía

Buscar un cajón por número es directo; revisar todas las secciones tarda más cuando el mueble crece; partir una guía ordenada por la mitad descarta muchas páginas a la vez.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `1024 visitas` frente a `10 pasos`. Es una comparación de crecimiento, no un cronómetro.

## Practica

Compara n = 8, 16 y 32. Dibuja el crecimiento de n y del número de divisiones.

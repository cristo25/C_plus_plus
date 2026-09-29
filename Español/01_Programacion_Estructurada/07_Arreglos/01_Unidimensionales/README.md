# Arreglos unidimensionales

## Qué aprenderás

`array<int, 4>` guarda cuatro enteros contiguos. El tamaño es fijo y los índices van de 0 a 3. `at()` comprueba el índice; `[]` requiere que tú garantices que sea válido. Un arreglo tradicional se escribe `int datos[4]`, pero no ofrece `at()`.

## Analogía

Un arreglo es un cajón para un solo tipo de cosas, dividido en secciones numeradas desde cero. No cabe una quinta cosa en un cajón de cuatro secciones.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `Suma original: 100`.

## Practica

Crea un cajón de cinco calificaciones y calcula su promedio con división decimal.

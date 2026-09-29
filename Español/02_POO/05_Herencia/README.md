# Herencia

## Qué aprenderás

Una clase derivada reutiliza una base cuando existe una relación «es un». La herencia pública conserva esa relación para el usuario de la clase. Prefiere composición cuando la relación sea «tiene un».

## Analogía

Una bicicleta eléctrica sigue siendo una bicicleta y añade una batería.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `Velocidad: 5`. Esta base no se usa para destruir objetos derivados mediante punteros; el siguiente tema presenta el destructor virtual.

## Practica

Consume la batería con un ciclo y verifica que no baje de cero.

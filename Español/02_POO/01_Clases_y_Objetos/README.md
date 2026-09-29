# Clases y objetos

## Qué aprenderás

Una clase define datos y operaciones; un objeto es una instancia concreta. `public` permite usar esos miembros desde fuera. En el siguiente tema protegeremos los datos con `private`.

## Analogía

La clase es el plano de una bicicleta; cada bicicleta construida es un objeto con su propio color.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `Bicicleta roja: 5`.

## Practica

Agrega un método `frenar` y verifica que los objetos mantengan estados independientes.

La bicicleta azul también se muestra, con velocidad `0`, para observar que tiene su propio estado.

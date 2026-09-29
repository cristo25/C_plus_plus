# Encapsulamiento y const

## Qué aprenderás

`private` protege el estado. Los métodos públicos controlan cambios válidos; los métodos `const` consultan sin modificar el objeto. No necesitas un getter y un setter por cada atributo.

## Analogía

Una alcancía no deja meter la mano directamente: sus operaciones controlan cómo entra y sale el dinero.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Salida: `300 centavos`. El ejemplo limita el saldo a 1 000 000 de centavos y rechaza operaciones inválidas.

## Practica

Comprueba que no puedes acceder a `saldo` directamente desde `main`. Prueba retirar cero.

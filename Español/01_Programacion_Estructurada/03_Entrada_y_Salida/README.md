# Leer y mostrar datos

## Qué aprenderás

`getline` lee una línea completa. `getline(cin, ...)` captura la edad como texto y un `istringstream` la interpreta; comprueba el resultado antes de usarlos. Una entrada incorrecta debe producir un mensaje y terminar sin calcular con datos inválidos.

## Analogía

La consola es una ventanilla: entra una solicitud, verificas que esté completa y entregas una respuesta.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
./programa.exe
```

Introduce `Ada` y después `20`. Verás `Hola, Ada. Tienes 20 anios.`. Comprueba también una edad negativa y un texto en lugar de la edad.

Este ejemplo valida la entrada con condiciones y devuelve código 1 cuando es inválida.

## Practica

Solicita la ciudad con `getline`. Si mezclas `>>` y `getline`, consume antes el salto de línea pendiente.

Se lee la línea completa para rechazar texto sobrante como `20abc`, y se rechazan nombres formados solo por espacios.

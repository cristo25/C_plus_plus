# Const y headers en EDD

## Qué aprenderás

Una consulta de una estructura puede recibir `const vector<int>&`: usa sus elementos sin copiar ni cambiar el vector. El vector y el resultado del ejemplo son `const`. El header declara la operación y una constante `inline constexpr`; el `.cpp` define el algoritmo con `count_if` y `main.cpp` lo usa. La consulta revisa cada elemento una vez; con el doble de elementos hace el doble de visitas (O(n), donde n es la cantidad de elementos). Solo agrega un contador y unas pocas variables, sin crear otra colección del mismo tamaño (O(1) de memoria adicional).

Los ejemplos de listas, árboles y grafos ya tienen headers con clases y operaciones. Aquí se muestra la separación entre declaración e implementación para una consulta. Comparar esta firma con un ordenamiento que recibe `vector<int>&` ayuda a distinguir lectura y modificación.

## Analogía

Una consulta es revisar el cajón a través de una vitrina: cuentas los objetos sin cambiar su posición. Ordenar el cajón sí exige abrirlo y moverlos.

## Ejecuta el ejemplo

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Consultas.cpp -o programa.exe
./programa.exe
```

Salida:

```text
Valores mayores a 7: 2
9 4 10 6
```

## Practica

Agrega una consulta para contar valores menores sin modificar los datos. Prueba un vector vacío y verifica que dé 0. Intenta ordenar el vector `const` y observa el error del compilador; para ordenarlo debes crear una copia mutable.

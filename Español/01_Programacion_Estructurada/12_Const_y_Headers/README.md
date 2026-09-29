# Const y headers en programación estructurada

## Qué aprenderás

`const` impide cambiar un dato desde su declaración. Las notas y el promedio de este ejemplo no cambian, por eso son constantes. `const array<int, 3>&` permite consultar las notas sin copiarlas ni modificarlas. `constexpr` indica que un valor puede evaluarse en compilación; las constantes `inline constexpr` del header se pueden compartir entre archivos de implementación.

`Calificaciones.h` declara las funciones y sus constantes. `Calificaciones.cpp` define las operaciones. `main.cpp` organiza la ejecución. No hace falta una clase para dividir un programa en archivos.

## Analogía

El header es una ficha de instrucciones: dice qué servicio puedes pedir. El `.cpp` realiza el trabajo. `const` pone una vitrina sobre el cajón: puedes ver sus notas sin moverlas.

## Ejecuta el ejemplo

Desde esta carpeta:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Calificaciones.cpp -o programa.exe
./programa.exe
```

Salida:

```text
Promedio: 9
Aprobado
```

Compila los dos `.cpp`; incluye el `.h`, nunca el `.cpp`. Las guardas evitan declaraciones repetidas y el namespace mantiene los nombres del curso agrupados. Las notas fuera de 0 a 10 producen un mensaje y código de salida 1.

## Practica

Intenta cambiar una nota después de declararla: el compilador rechazará la asignación. Luego cambia sus valores **en la declaración** a `{4, 5, 6}` y observa `Reprobado`. Declara y define una función que encuentre la nota más alta sin modificar el arreglo.

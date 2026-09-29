# Const, headers y compilación de varios archivos

## Qué aprenderás

`Producto.h` declara la clase; `Producto.cpp` define sus métodos; `main.cpp` la utiliza. Las guardas `#ifndef` evitan incluir la misma declaración dos veces. Cada `.cpp` se compila y el enlazador reúne el resultado. Incluye el `.h`, nunca el `.cpp`.

## Analogía

El header es la carta del restaurante: explica qué puedes pedir. El `.cpp` es la cocina y `main` hace el pedido.

## Ejecuta el ejemplo

Abre una terminal **en esta carpeta**. Necesitas un compilador compatible con C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Producto.cpp -o programa.exe
./programa.exe
```

Salida: `Cuaderno: 1250 centavos`. Compila **ambos** archivos `.cpp`; si omites `Producto.cpp`, faltarán las definiciones al enlazar.

## Practica

Agrega una consulta de precio con descuento. Declárala en el header y defínela en `Producto.cpp`.

Los headers usan `namespace curso { using namespace std; ... }`; los `.cpp` importan `curso` para acceder a sus declaraciones. Así el header no agrega nombres estándar al namespace global del archivo que lo incluye.

## Const aplicado a una clase

`main.cpp` crea un `const Producto`: puedes consultar su nombre y precio, pero no modificarlo. Las consultas se declaran con `const` después de los paréntesis tanto en el `.h` como en el `.cpp`. Eso permite llamarlas desde un objeto constante. La consulta del nombre devuelve `const string&` para evitar una copia y proteger el texto original.

Así se distinguen tres usos: `const` en datos que no cambian, `const T&` en parámetros o resultados de solo lectura, y métodos `const` que consultan el estado del objeto. Un método que cambia el precio no debería ser const.

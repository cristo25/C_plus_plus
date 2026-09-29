// Variables, tipos y operadores
//
// Vamos a guardar datos en variables. Podemos pensar en cada variable como una caja con nombre: int
// guarda enteros, double y float guardan números con decimales, char guarda un carácter, bool
// guarda verdadero o falso y string guarda texto. En cantidad guardamos cuántos cuadernos hay;
// multiplicamos ese número por precio para obtener total. Con const protegemos un dato que no debe
// cambiar. Al dividir dos enteros descartamos la parte decimal: 5 / 2 da 2, mientras que 5.0 / 2 da
// 2.5.
//
// Practica: Realiza un programa que calcule el importe de una compra.
//
// - Guardar nombre, cantidad y precio de un producto.
// - Calcular y mostrar el total con decimales.
// - Usar const para un precio que no cambiará durante el programa.

#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

int main() {
    // const protege los datos que no cambian; cantidad sigue siendo una variable modificable.
    const string producto = "Cuaderno";
    int cantidad = 3;
    const double precio = 12.5;
    const char categoria = 'A';
    const bool disponible = cantidad > 0;
    const double total = cantidad * precio;

    cout << producto << ": " << total << "\n";
    cout << categoria << " disponible: " << boolalpha << disponible << "\n";
    // Al dividir enteros obtenemos 2 en 5 / 2; con 5.0 / 2 conservamos el decimal.
    cout << "Division entera: " << 5 / 2 << "\n";
    cout << "Division decimal: " << 5.0 / 2 << "\n";
}

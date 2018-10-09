/*
Sergio Campoy Maldonado, Fundamentos de Programación 1ºC

Programa que escribe los dígitos de un número dado separados por barras "|"
*/

#include <iostream>

#include <cmath>     // Necesaria para la potencia y el logaritmo

using namespace std;

int main () {
   // Declaración de variables
   int n, digitos_n;

   // Entrada de datos
   do {
      cout << "Introduce un número entero positivo: ";
      cin >> n;
   } while (n < 0);

   // Cálculos
   digitos_n = log(n) / log(10) + 1;

   // "Salida"
   cout << endl << "|";
   for (int i=1; i <= digitos_n; i++) {
      int aux = pow (10, digitos_n - i);
      cout << n / aux;
      cout << "|";
      n = n % aux;
   }
}

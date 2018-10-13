/*
Sergio Campoy Maldonado, Fundamentos de Programación 1ºC

Programa que escribe todos los divisores de un número dado
*/

#include <iostream>

using namespace std;

int main () {
   // Declaración de variables
   int n;   // Número al que calcularemos los divisores

   // Entrada de datos
   do {
      cout << "Introduce un entero positivo: ";
      cin >> n;
   } while(n < 0);

   // Cálculos
   int i = 1;  // Variable que usaremos de "contador"
   while (i <= n) {
      if (n % i == 0) {
         cout << i << " es divisor de " << n << endl;
      }
      i++;
   }
}

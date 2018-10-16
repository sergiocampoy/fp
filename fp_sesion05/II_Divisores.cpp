/*
Sergio Campoy Maldonado, Fundamentos de Programaci�n 1�C

Programa que escribe todos los divisores de un n�mero dado
*/

#include <iostream>

using namespace std;

int main () {
   // Declaraci�n de variables
   int n;   // N�mero al que calcularemos los divisores

   // Entrada de datos
   do {
      cout << "Introduce un entero positivo: ";
      cin >> n;
   } while(n < 0);

   // C�lculos
   int i = 1;  // Variable que usaremos de "contador"
   while (i <= n) {
      if (n % i == 0) {
         cout << i << " es divisor de " << n << endl;
      }
      i++;
   }
}

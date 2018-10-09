/*
Sergio Campoy Maldonado, Fundamentos de Programación 1ºC

Programa que escribe los divisores de un número dado
*/

#include <iostream>
#include <cmath>     // Necesario para la raíz cuadrada
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
   while (i <= sqrt(n)) {  /**Leer final***************************************/
      if (n % i == 0) {
         cout << i << " es divisor de " << n << endl;
      }
      i++;
   }
}
/*
No es necesario probar todos los números hasta n ya que el posible divisor más
grande de 'n' sería sqrt(n). Esto reduce el número de iteraciones
considerablemente
*/

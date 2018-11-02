/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que calcula el mayor número perfecto que sea menor a un número dado por
el usuario.
Un número perfecto es aquel cuya suma de divisores salvo él mismo es igual a el
número
*/

#include <iostream>

using namespace std;



int Suma_Divisores (int n) {
	//	Declaración de constantes
	const int TOPE = n / 2;
	
	//	Declaración de variables
	int suma = 0;
	
	//	Cálculos
	for (int i = 1; i <= TOPE; i++) {
		if ((n % i) == 0)
			suma += i;
	}
	
	//	Return
	return suma;
}



int main (void) {
	//	Declaración de variables
	int n, a;
	
	//	Entrada de datos
	do {
		cout << "Introduce un numero entero positivo: ";
		cin >> n;
	} while (n <= 0);
	
	a = n;
	
	//	Cálculo
	while (Suma_Divisores (a) != a) {
		a--;
	}
	
	//	Salida
	cout << "El mayor numero perfecto menor que " << n << " es " << a << endl;
	
	return 0;
}

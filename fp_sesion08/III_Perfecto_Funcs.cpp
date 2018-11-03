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

#include <cmath>

using namespace std;

/******************************************************************************/
//	Función:		Suma_Divisores
//	Recibe:		int n: Número al que se le calculará la suma de sus divisores
//	Devuelve:	int suma: Suma de los divisores de n (salvo n)
/******************************************************************************/

int Suma_Divisores (int n) {
	
	//	Declaración de constantes
	const int TOPE = floor (sqrt (n));
	
	//	Declaración de variables
	int suma = 1;
	double raiz = sqrt (n);
	
	//	Cálculos
	for (int i = 2; i <= TOPE; i++) {
		if (n % i == 0) {
			suma += i + n/i;
		}
	}
	
	if (raiz == TOPE)
	suma -= TOPE;
	
	
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

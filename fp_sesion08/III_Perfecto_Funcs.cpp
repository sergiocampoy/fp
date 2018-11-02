/*
Sergio Campoy Maldonado
Fundamentos de Programaci�n
1�C

Programa que calcula el mayor n�mero perfecto que sea menor a un n�mero dado por
el usuario.
Un n�mero perfecto es aquel cuya suma de divisores salvo �l mismo es igual a el
n�mero
*/

#include <iostream>

using namespace std;



int Suma_Divisores (int n) {
	//	Declaraci�n de constantes
	const int TOPE = n / 2;
	
	//	Declaraci�n de variables
	int suma = 0;
	
	//	C�lculos
	for (int i = 1; i <= TOPE; i++) {
		if ((n % i) == 0)
			suma += i;
	}
	
	//	Return
	return suma;
}



int main (void) {
	//	Declaraci�n de variables
	int n, a;
	
	//	Entrada de datos
	do {
		cout << "Introduce un numero entero positivo: ";
		cin >> n;
	} while (n <= 0);
	
	a = n;
	
	//	C�lculo
	while (Suma_Divisores (a) != a) {
		a--;
	}
	
	//	Salida
	cout << "El mayor numero perfecto menor que " << n << " es " << a << endl;
	
	return 0;
}

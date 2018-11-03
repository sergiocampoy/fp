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

#include <cmath>

using namespace std;

/******************************************************************************/
//	Funci�n:		Suma_Divisores
//	Recibe:		int n: N�mero al que se le calcular� la suma de sus divisores
//	Devuelve:	int suma: Suma de los divisores de n (salvo n)
/******************************************************************************/

int Suma_Divisores (int n) {
	
	//	Declaraci�n de constantes
	const int TOPE = floor (sqrt (n));
	
	//	Declaraci�n de variables
	int suma = 1;
	double raiz = sqrt (n);
	
	//	C�lculos
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

/*
Sergio Campoy Maldonado
Fundamentos de Programaci�n
1�C

Programa que muestra todos los n�meros triangulares menores que un n�mero entero
dado por el usuario
*/

#include <iostream>

using namespace std;

/******************************************************************************/
//	Funci�n: 	N_Esimo_Triangular
//	Recibe:		int n: Se calcular� el numero triangular n� n
//	Devuelve:	int suma: en�simo n�mero triangular
//PRE:			n > 0
/******************************************************************************/

int N_Esimo_Triangular (int n) {
	
	//	Declaraci�n de variables
	int suma = 0;
	
	//	C�lculos
	for (int i = 1; i <= n; i++) {
		suma += i;
	}
	
	//	Return
	return suma;
}

int main (void) {
	
	//	Declaraci�n de variables
	int n, contador = 1, triangular;
	
	//	Entrada de datos
	do {
		cout << "Introduce un numero natural: ";
		cin >> n;
	} while (n <= 0);
	
	triangular = N_Esimo_Triangular (contador);
	
	cout << "Los siguientes numeros triangulares son menores que " << n << ":"
		  << endl;
	
	while (triangular < n) {
		cout << "\t" << triangular << endl;
		contador++;
		triangular = N_Esimo_Triangular (contador);
	}
	
	return 0;
}

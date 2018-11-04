/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que muestra todos los números triangulares menores que un número entero
dado por el usuario
*/

#include <iostream>

using namespace std;

/******************************************************************************/
//	Función: 	N_Esimo_Triangular
//	Recibe:		int n: Se calculará el numero triangular nº n
//	Devuelve:	int suma: enésimo número triangular
//PRE:			n > 0
/******************************************************************************/

int N_Esimo_Triangular (int n) {
	
	//	Declaración de variables
	int suma = 0;
	
	//	Cálculos
	for (int i = 1; i <= n; i++) {
		suma += i;
	}
	
	//	Return
	return suma;
}

int main (void) {
	
	//	Declaración de variables
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

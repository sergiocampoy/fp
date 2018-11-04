#include <iostream>
#include <string>
using namespace std;

/******************************************************************************/
//	Función:		Cuadrado
//	Recibe:		double x: Número al que se le va a calcular el cuadrado
//	Devuelve:	x^2
/******************************************************************************/

double Cuadrado (double x) {
	return (x*x);
}

/******************************************************************************/
//	Función:		Cuenta_Cifras
//	Recibe:		int n: Número al que se le contarán las cifras
//	Devuelve:	nº de cifras del número n
/******************************************************************************/

int Cuenta_Cifras (int n) {
	return ((to_string (n)).length());
}

/******************************************************************************/
//	Función: 	Digito_n
//	Recibe:		int pos:	Posición en la que se encuentra el dígito que queremos
//					int n:	Número del cual se va a "extraer" el dígito
//	Devuelve:	El dígito en la posición "pos" del número "n"
//	PRE:			pos <= Cuenta_Cifas (n)
/******************************************************************************/

int Digito_n (int pos, int n) {
	string cad = to_string (n);
	
	return (cad.at (pos - 1) - '0');
}

/******************************************************************************/
//	Función: 	Es_Feliz
//	Recibe:		int n:	Número a comprobar si es feliz
//					int k:	Grado máximo a comprobar
//	Devuelve:	TRUE:		Si n es un número feliz de grado k
//					FALSE:	Si n no es un número feliz de grado k
/******************************************************************************/

bool Es_Feliz (int n, int k) {
	//	Declaración de variables
	int suma = 0;

	//	Cálculo
	for (int i = 1; i <= Cuenta_Cifras (n); i++) {
		suma += Cuadrado (Digito_n (i, n));
	}

	if (suma == 1)
		return true;
	else if (k == 1)
		return false;
	else
		return (Es_Feliz (suma, k-1));
}



int main (void) {
	//	Declaración de variables
	int n, k;
	
	//	Entrada de datos
	do {
		cout << "Introduce el grado del numero feliz: ";
		cin >> k;
	} while (k <= 0);
	
	do {
		cout << "Introduce el numero que se quiere comprobar: ";
		cin >> n; 
	} while (n <= 0);
	
	
	//	Salida
	if (Es_Feliz (n, k))
		cout << endl
			  << n << " es un numero feliz de grado " << k
			  << endl << endl;
	else
		cout << endl
			  << n << " no es un numero feliz :("
			  << endl << endl;

	return 0;
}

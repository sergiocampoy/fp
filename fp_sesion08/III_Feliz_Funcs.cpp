#include <iostream>
#include <string>
using namespace std;

/******************************************************************************/
//	Funci�n:		Cuadrado
//	Recibe:		double x: N�mero al que se le va a calcular el cuadrado
//	Devuelve:	x^2
/******************************************************************************/

double Cuadrado (double x) {
	return (x*x);
}

/******************************************************************************/
//	Funci�n:		Cuenta_Cifras
//	Recibe:		int n: N�mero al que se le contar�n las cifras
//	Devuelve:	n� de cifras del n�mero n
/******************************************************************************/

int Cuenta_Cifras (int n) {
	return ((to_string (n)).length());
}

/******************************************************************************/
//	Funci�n: 	Digito_n
//	Recibe:		int pos:	Posici�n en la que se encuentra el d�gito que queremos
//					int n:	N�mero del cual se va a "extraer" el d�gito
//	Devuelve:	El d�gito en la posici�n "pos" del n�mero "n"
//	PRE:			pos <= Cuenta_Cifas (n)
/******************************************************************************/

int Digito_n (int pos, int n) {
	string cad = to_string (n);
	
	return (cad.at (pos - 1) - '0');
}

/******************************************************************************/
//	Funci�n: 	Es_Feliz
//	Recibe:		int n:	N�mero a comprobar si es feliz
//					int k:	Grado m�ximo a comprobar
//	Devuelve:	TRUE:		Si n es un n�mero feliz de grado k
//					FALSE:	Si n no es un n�mero feliz de grado k
/******************************************************************************/

bool Es_Feliz (int n, int k) {
	//	Declaraci�n de variables
	int suma = 0;

	//	C�lculo
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
	//	Declaraci�n de variables
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

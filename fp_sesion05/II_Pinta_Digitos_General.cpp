/*
Sergio Campoy Maldonado, Fundamentos de Programaci�n 1�C

Programa que escribe los d�gitos de un numero introducido separados por '|'
*/

#include <iostream>

#include <cmath>	//	Necesaria para la potencia

using namespace std;

int main () {
	//	Declaraci�n de variables
	int n, digito, n_aux;
	int digitos_n = 0;	//	Variable "contador"
	
	//	Entrada
	do {
		cout << "Introduce un numero entero positivo: ";
		cin >> n;
	} while (n < 0);
	
	//	C�lculo
		//	C�lculo de d�gitos de n
	while (n >= pow (10, digitos_n)) {
		digitos_n ++;
	}
	
		//	"Salida"
	n_aux = n;
	cout << endl << "|";
	while (digitos_n != 0) {
		digito = n_aux / pow (10, digitos_n - 1);			//	D�gito que va a pintar
		n_aux = n_aux - digito * pow(10, digitos_n - 1);
		
		cout << digito << "|";
		digitos_n --;
	}
}

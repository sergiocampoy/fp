/*
Sergio Campoy Maldonado, Fundamentos de Programaci�n 1�C

Programa que escribe los d�gitos de un numero introducido separados por '|',
esta vez diferenciando claramente la entrada, los c�lculos y la salida
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main () {
	//	Declaraci�n de variables
	int n, digito, n_aux;
	int digitos_n = 0;	//	Variable "contador"
	string resultado = "";	//	String donde se guardar� la salida
	
	//	Entrada de datos
	do {
		cout << "Introduce un numero entero positivo: ";
		cin >> n;
	} while (n < 0);
	
	//	C�lculos
		//	C�lculo de d�gitos de n
	while (n > pow (10, digitos_n)) {
		digitos_n++;
	}
	n_aux = n;
	
		//	C�lculo del string
	resultado = resultado + "|";
	while (digitos_n != 0) {
		digito = n_aux / pow (10, digitos_n - 1);			//	D�gito que va a pintar
		n_aux = n_aux - digito * pow(10, digitos_n - 1);
		
		resultado = resultado + to_string(digito) + "|";
		digitos_n --;
	}
	
	//	Salida
	cout << endl
		  << resultado << endl << endl;
	
}

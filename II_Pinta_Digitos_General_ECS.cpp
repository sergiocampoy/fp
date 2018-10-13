/*
Sergio Campoy Maldonado, Fundamentos de Programación 1ºC

Programa que escribe los dígitos de un numero introducido separados por '|',
esta vez diferenciando claramente la entrada, los cálculos y la salida
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main () {
	//	Declaración de variables
	int n, digito, n_aux;
	int digitos_n = 0;	//	Variable "contador"
	string resultado = "";	//	String donde se guardará la salida
	
	//	Entrada de datos
	do {
		cout << "Introduce un numero entero positivo: ";
		cin >> n;
	} while (n < 0);
	
	//	Cálculos
		//	Cálculo de dígitos de n
	while (n > pow (10, digitos_n)) {
		digitos_n++;
	}
	n_aux = n;
	
		//	Cálculo del string
	resultado = resultado + "|";
	while (digitos_n != 0) {
		digito = n_aux / pow (10, digitos_n - 1);			//	Dígito que va a pintar
		n_aux = n_aux - digito * pow(10, digitos_n - 1);
		
		resultado = resultado + to_string(digito) + "|";
		digitos_n --;
	}
	
	//	Salida
	cout << endl
		  << resultado << endl << endl;
	
}

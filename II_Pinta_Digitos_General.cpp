/*
Sergio Campoy Maldonado, Fundamentos de Programación 1ºC

Programa que escribe los dígitos de un numero introducido separados por '|'
*/

#include <iostream>

#include <cmath>	//	Necesaria para la potencia

using namespace std;

int main () {
	//	Declaración de variables
	int n, digito, n_aux;
	int digitos_n = 0;	//	Variable "contador"
	
	//	Entrada
	do {
		cout << "Introduce un numero entero positivo: ";
		cin >> n;
	} while (n < 0);
	
	//	Cálculo
		//	Cálculo de dígitos de n
	while (n >= pow (10, digitos_n)) {
		digitos_n ++;
	}
	
		//	"Salida"
	n_aux = n;
	cout << endl << "|";
	while (digitos_n != 0) {
		digito = n_aux / pow (10, digitos_n - 1);			//	Dígito que va a pintar
		n_aux = n_aux - digito * pow(10, digitos_n - 1);
		
		cout << digito << "|";
		digitos_n --;
	}
}

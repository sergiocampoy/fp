/*
Sergio Campoy Maldonado, Fundamentos de Programación 1ºC

Programa que escribe los dígitos de un numero introducido separados por '|',
esta vez haciendo uso de una función
*/

#include <iostream>

#include <string>

using namespace std;

string Entero2String (string entero) {
	//	Declaración de variables
	string cadena = "|";
	int cifras_n;
	
	//	Cálculos
	cifras_n = entero.length ();
	
	for (int i = 0; i < cifras_n; i++)
		cadena = cadena + entero.at(i) + "|";
	
	//	Return
	return cadena;
}

int main (void) {
	//	Declaración de variables
	int entero;
	
	//	Entrada
	do {
		cout << "Introduce un entero positivo: ";
		cin >> entero;
	}	while (entero < 0);
	
	//	Salida
	cout << Entero2String (to_string (entero));
	
	return 0;
}

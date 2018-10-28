/*
Sergio Campoy Maldonado, Fundamentos de Programaci�n 1�C

Programa que escribe los d�gitos de un numero introducido separados por '|',
esta vez haciendo uso de una funci�n
*/

#include <iostream>

#include <string>

using namespace std;

string Entero2String (string entero) {
	//	Declaraci�n de variables
	string cadena = "|";
	int cifras_n;
	
	//	C�lculos
	cifras_n = entero.length ();
	
	for (int i = 0; i < cifras_n; i++)
		cadena = cadena + entero.at(i) + "|";
	
	//	Return
	return cadena;
}

int main (void) {
	//	Declaraci�n de variables
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

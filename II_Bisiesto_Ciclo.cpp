/*
Sergio Campoy Maldonado, Fundamentos de Programaci�n 1�C

Programa que devuelve los a�os bisiestos entre dos a�os dados
*/

#include <iostream>
using namespace std;

int main () {
	//	Declaraci�n de variables
	int year1, year2;
	bool multi4, multi100, multi400;
	
	//	Entrada de datos
	do {
		cout << "Introduce el anyo inicial: ";
		cin >> year1;
	} while (year1 < 1900);
	
	do {
		cout << "Introduce el anyo final: ";
		cin >> year2;
	} while (year2 < 1900);
	
	//	C�lculos
	int i = year1;	//	Variable contador
	while (i <= year2) {
		multi4 = (i % 4 == 0);
		multi100 = (i % 100 == 0);
		multi400 = (i % 400 == 0);
		
		if ((multi4 && !multi100) || (multi400))
			cout << i << " es bisiesto" << endl;
		i++;
	}
}

/*
Sergio Campoy Maldonado, Fundamentos de Programación 1ºC

Programa que recibe números reales y calcula cuantos números ha recibido,
el máximo y el mínimo
*/

#include <iostream>

using namespace std;

int main () {
	//	Declaración de constantes
	const int Terminador = 0;
	
	//	Declaración de variables
	double dato;
	double max, min;
	int i = 0;	//	Variable contador
	
	//	Entrada de datos
	cout << "Introduce un número real: ";
	cin >> dato;
	

	max = dato;
	min = dato;

	while (dato != Terminador) {
		i++;
		if (dato > max)
			max = dato;
		if (dato < min)
			min = dato;
			
		cout << "Introduce un número real: ";
		cin >> dato;
	}
	
	//	Salida
	if (i != 0) {
		cout << endl
			  << "La entrada ha terminado" << endl << endl;
		cout << "\tSe han introducido " << i << " datos" << endl;
		cout << "\tEl maximo ha sido " << max << endl;
		cout << "\tEl minimo ha sido " << min << endl << endl;
	}
	else
		cout << "No se han introducido datos." << endl;
}

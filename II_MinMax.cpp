/*
Sergio Campoy Maldonado, Fundamentos de Programación 1ºC

Programa que recibe números enteros y calcula el número de número recibidos,
el máximo y el mínimo recibidos
*/

#include <iostream>

using namespace std;

int main () {
	//	Declaración de constantes
	const int Terminador = 0;
	
	//	Declaración de variables
	double dato;
	double max, min;
	double i = 0;	//	Variable contador
	
	//	Entrada de datos
	cout << "Introduce un número real: ";
	cin >> dato;
	
	if (dato != Terminador) {
	max = dato;
	min = dato;
	}
	
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
	cout << endl
		  << "La entrada ha terminado" << endl << endl;
	cout << "\tSe han introducido " << i << " datos" << endl;
	cout << "\tEl maximo ha sido " << max << endl;
	cout << "\tEl minimo ha sido " << min << endl << endl;
}

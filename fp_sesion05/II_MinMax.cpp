/*
Sergio Campoy Maldonado, Fundamentos de Programaci�n 1�C

Programa que recibe n�meros reales y calcula cuantos n�meros ha recibido,
el m�ximo y el m�nimo
*/

#include <iostream>

using namespace std;

int main () {
	//	Declaraci�n de constantes
	const int Terminador = 0;
	
	//	Declaraci�n de variables
	double dato;
	double max, min;
	int i = 0;	//	Variable contador
	
	//	Entrada de datos
	cout << "Introduce un n�mero real: ";
	cin >> dato;
	

	max = dato;
	min = dato;

	while (dato != Terminador) {
		i++;
		if (dato > max)
			max = dato;
		if (dato < min)
			min = dato;
			
		cout << "Introduce un n�mero real: ";
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

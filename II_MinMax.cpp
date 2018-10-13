/*
Sergio Campoy Maldonado, Fundamentos de Programaci�n 1�C

Programa que recibe n�meros enteros y calcula el n�mero de n�mero recibidos,
el m�ximo y el m�nimo recibidos
*/

#include <iostream>

using namespace std;

int main () {
	//	Declaraci�n de constantes
	const int Terminador = 0;
	
	//	Declaraci�n de variables
	double dato;
	double max, min;
	double i = 0;	//	Variable contador
	
	//	Entrada de datos
	cout << "Introduce un n�mero real: ";
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
		cout << "Introduce un n�mero real: ";
		cin >> dato;
	}
	
	//	Salida
	cout << endl
		  << "La entrada ha terminado" << endl << endl;
	cout << "\tSe han introducido " << i << " datos" << endl;
	cout << "\tEl maximo ha sido " << max << endl;
	cout << "\tEl minimo ha sido " << min << endl << endl;
}

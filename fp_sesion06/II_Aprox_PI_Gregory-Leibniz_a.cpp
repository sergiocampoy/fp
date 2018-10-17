/*
Sergio Campoy Maldonado, Fundamentos de Programaci�n 1�C

Programa que calcula un valor aproximado de Pi usando la serie de
Gregory-Leibniz. Hace uso de la biblioteca <cmath>
*/

#include <iostream>
#include <cmath>
using namespace std;

int main () {
	//	Declaraci�n de constantes
	const int Inicio = 0, Fin = 100000;
	
	//	Declaraci�n de variables
	double pi, pi_cuartos = 0;
	
	//	C�lculos
	for (int i = Inicio; i <= Fin; i++) {
		pi_cuartos += pow (-1, i) / (2*i + 1);
	}
	pi = 4 * pi_cuartos;
	
	//	Salida
	cout << "Pi es aproximadamente igual a " << pi
		  << endl << endl;
}

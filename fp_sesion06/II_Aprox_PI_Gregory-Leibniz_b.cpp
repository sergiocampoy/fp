/*
Sergio Campoy Maldonado, Fundamentos de Programación 1ºC

Programa que calcula un valor aproximado de Pi usando la serie de
Gregory-Leibniz. NO hace uso de la biblioteca <cmath>
*/

#include <iostream>

using namespace std;

int main () {
	//	Declaración de constantes
	const int Inicio = 0, Fin = 100000;
	
	//	Declaración de variables
	double pi, pi_cuartos = 0;
	
	//	Cálculos
	for (int i = Inicio; i <= Fin; i++) {
		if (i % 2 == 0)
			pi_cuartos += 1.0 / (2*i + 1);
		else
			pi_cuartos -= 1.0 / (2*i + 1);
	}
	pi = 4 * pi_cuartos;
	
	//	Salida
	cout << "Pi es aproximadamente igual a " << pi
		  << endl << endl;
}

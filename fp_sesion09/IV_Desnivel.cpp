/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Progrma que recibe un vector de alturas medidas por un GPS y calcula el máximo
desnivel entre dos alturas consecutivas y el desnivel positivo total
*/

#include <iostream>

#include <cmath>

using namespace std;

int main (void) {

	//	Declaración de constantes
	const int SIZE = 100;
	
	//	Declaración de variables
	int altura [SIZE];
	int usados;
	int delta;
	int delta_max = 0;
	int delta_positivo = 0;
	
	//	Entrada
	do {
		cout << "Cuantos valores se van a introducir? ";
		cin >> usados;
	} while (usados <= 0);
	
	for (int i = 0; i < usados; i++) {
		cin >> altura [i];
	}
	
	//	Cálculos
	for (int i = 1; i < usados; i++) {
		delta = altura[i] - altura [i-1];
		
		(delta > 0) ? (delta_positivo += delta) : (delta = -delta);
		
		if (delta > delta_max)
			delta_max = delta;
	}
	
	//	Salida
	cout << endl
		  << "El maximo desnivel en valor absoluto ha sido " << delta_max
		  << endl
		  << "El desnivel acumulado positivo ha sido " << delta_positivo
		  << endl << endl;
	
	return 0;
}

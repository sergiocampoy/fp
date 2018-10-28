/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que calcula el menor valor de i que hace que la aproximación del número
áureo mediante la fórmula basada en los números de Fibonacci sea menor de un
error dado por el usuario.
*/

#include <iostream>

#include <cmath>

using namespace std;

int Fibonacci (int n) {
	int n_esimo_fibonacci = 1, n1 = 1, n2 = 1;
	
	for (int i = 3; i <= n; i++) {
		n_esimo_fibonacci = n1 + n2;
		n2 = n1;
		n1 = n_esimo_fibonacci;
	}
	
	return n_esimo_fibonacci;
}

double Aureo (int precision) {
	return (1.0*Fibonacci (precision + 1) / Fibonacci (precision));
}

bool Error_mayor (double a, double b, double delta) {
	return (abs ( a - b ) > delta);
}

int main (void) {
	const double n_aureo = (1 + sqrt(5)) / 2;
	double error;
	int i = 1;
	
	do {
		cout << "Introduce el valor del error: ";
		cin >> error;
	} while (error <= 0);
	
	while (Error_mayor (n_aureo, Aureo (i), error))
		i++;
	
	cout << "n = " << i;
	
	return 0;
}

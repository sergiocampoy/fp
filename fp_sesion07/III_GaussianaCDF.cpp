/*
Sergio Campoy Maldonado
Fundamentos de Programaci�n
1�C

Programa que calcula el �rea de la Campana de Gauss de media 0 y desviaci�n
t�pica 1 en el intervalo ]-inf, x]
*/

#include <iostream>

#include <cmath>

using namespace std;

//	Declaraci�n de constantes globales
const double PI = 3.14159;

double Cuadrado (double x) {
	
	return (x*x);
}

double Gaussiana_estandar (double x) {
	
	return (exp (Cuadrado (x) / -2) / sqrt (2*PI));
}

double Funcion_CDF (double x) {
	
	//	Declaraci�n de constantes
	const double b0 = 0.2316419, b1 = 0.319381530, b2 = -0.356563782,
		b3 = 1.781477937, b4 = -1.821255978, b5 = 1.330274429;
	
	
	//	Declaraci�n de variables
	double w, t = 1.0 / (1 + b0 * abs (x));
	
	
	//	C�lculos
	w = 1 - Gaussiana_estandar (abs (x)) *
		(b1*t + b2*pow(t, 2) + b3*pow(t, 3) + b4*pow(t, 4) + b5*pow(t, 5));
	
	
	//	Salida
	if (x < 0)
		return (1 - w);
	else
		return w;
}

int main (void) {
	
	//	Declaraci�n de variables
	double area, x;
	
	
	//	Entrada
	cout << "Introduce un valor para x: ";
	cin >> x;


	//	C�lculos
	area = Funcion_CDF (x);

	//	Salida
	cout << endl
		  << "El area de la funcion hasta " << x << " es " << area
		  << endl << endl;

	//	Return
	return 0;
}

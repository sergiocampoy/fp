/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que:
	a) Pide los coeficientes de dos rectas

	b) Muestra los puntos por los que pasa la recta y sus valores son
			x = {-10, -9, ... , 10}, y = {-5, -4.5, -4, ... , 5}

	c) Escribe la ecuación explicita de las rectas de usando y sin usar strings
	
	d) Indica la posición relativa de las rectas
*/

#include <iostream>

#include <string>

#include <iomanip>

using namespace std;



double Pendiente (double a, double b) {
	
	return (-a / b);
}



double Ordenada_origen (double b, double c) {
	
	return (-c / b);
}



double Devuelve_y (double a, double b, double c, double x) {
	
	//	Declaración de variables
	double m, n, y;
	
	//	Cálculos
	m = Pendiente (a, b);
	n = Ordenada_origen (b, c);
	
	y = m*x + n;
	
	//	Salida
	return y;
}



double Devuelve_x (double a, double b, double c, double y) {
	
	//	Declaración de variables
	double m, n, x;
	
	//	Cálculos
	m = Pendiente (b, a);
	n = Ordenada_origen (a, c);
	
	x = m*y + n;
	
	//	Salida
	return x;
}



void Escribe_explicita (double a, double b, double c) {
	
	//	Declaración de variables
	double m, n;
	
	//	Cálculos
	m = Pendiente (a, b);
	n = Ordenada_origen (b, c);
	
	//	Salida
	cout << "y = " << m << "x + " << n;
}



string Devuelve_explicita (double a, double b, double c) {
	
	//	Declaración de variables
	double m, n;
	string funcion = "";
	
	//	Cálculos
	m = Pendiente (a, b);
	n = Ordenada_origen (b, c);
	
	funcion = "y = " + to_string (m) + "x + " + to_string (n);
	
	//	Salida
	return funcion;
}



string Posicion_relativa (double a1, double b1, double c1,
								  double a2, double b2, double c2) {

	if (Pendiente (a1, b1) == Pendiente (a2, b2))
		if (Ordenada_origen (b1, c1) == Ordenada_origen (b2, c2))
			return "coincidentes";
		else
			return "paralelas";
	else
		return "secantes";
}



void Devuelve_puntos (double a, double b, double c) {
	
	cout << "La recta pasa por los siguientes puntos: " << endl;
	
	for (double i = -10; i <= 10; i++) {
		
		cout << "\t(" << setw (7) << i
			  << ", " << setw (7) << Devuelve_y (a, b, c, i) << ")";
			  
		cout << "\t(" << setw (7) << Devuelve_x (a, b, c, i / 2.0)
			  << ", " << setw (7) << i / 2.0 << ")"
			  << endl;
	}
}

int main () {
	//	Ajustes de "cout"
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout << setprecision (3);
	
	
	//	Declaración de variables
	double a1, b1, c1;
	double a2, b2, c2;
	
	//	Entrada de datos
	cout << "r: Ax + By + C = 0"
		  << endl
		  << "s: A'x + B'y + C' = 0"
		  << endl << endl;
		  
	cout << "Introduce A: ";
	cin >> a1;
	cout << "Introduce B: ";
	cin >> b1;
	cout << "Introduce C: ";
	cin >> c1;
	
	cout << "Introduce A': ";
	cin >> a2;
	cout << "Introduce B': ";
	cin >> b2;
	cout << "Introduce C': ";
	cin >> c2;
	
	
	// Salidas
	//	b)
	cout << endl;
	Devuelve_puntos (a1, b1, c1);
	cout << endl;
	Devuelve_puntos (a2, b2, c2);
	cout << endl;
	
	
	//	c)
	cout << "La ecuacion expicita de la primera recta es:" << endl
		  << "\t";
	Escribe_explicita (a1, b1, c1);
	cout << "\t\t        (escribe directamente)" << endl;
	
	cout << "\t" << Devuelve_explicita (a1, b1, c1)
		  << "\t\t(devuelve string)" << endl;
	
	
	cout << "La ecuacion expicita de la primera recta es:" << endl
		  << "\t";
	Escribe_explicita (a2, b2, c2);
	cout << "\t\t        (escribe directamente)" << endl;
	
	cout << "\t" << Devuelve_explicita (a2, b2, c2)
		  << "\t\t(devuelve string)" << endl;
	
	
	//	d)
	cout << "Las rectas son " << Posicion_relativa (a1, b1, c1, a2, b2, c2)
		  << endl << endl;
}

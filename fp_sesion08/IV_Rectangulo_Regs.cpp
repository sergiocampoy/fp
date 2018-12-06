/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que recibe los parámetros de un rectángulo y calcula la circunferencia
centrada en la intersección de las diagonales del rectángulo cuya área es mayor
que la del rectángulo
*/

#include <iostream>

#include <cmath>

using namespace std;

//	Declaración de constantes
const double PI = 3.14159265358979323846;

//	Registros

struct Punto2D {
	double x, y;		//	Ordenada y abscisa del punto
};

struct Rectangulo {
	Punto2D p_si;		//	Coordenada superior izquierda del rectángulo
	Punto2D p_id;		//	Coordenada inferior derecha del rectángulo
};

struct Circunferencia {
	Punto2D centro;	//	Coordenadas del centro de la circunferencia
	double radio;		//	Radio de la circunferencia
};

/******************************************************************************/
//	Función:		Cuadrado
//	Recibe:		double x: Número que se elevará al cuadrado
//	Devuelve:	double x*x
/******************************************************************************/

double Cuadrado (double x) {
	return (x*x);
}

/******************************************************************************/
//	Función:		AreaRectangulo
//	Recibe:		Rectangulo rect
//	Devuelve:	Área del rectángulo (base x altura)
/******************************************************************************/

double AreaRectangulo (Rectangulo rect) {
	//	Declaración de variables
	double base, altura;
	
	//	Cálculos
	base = rect.p_id.x - rect.p_si.x;
	altura = rect.p_si.y - rect.p_id.y;
	
	//	Return
	return (base * altura);
}

/******************************************************************************/
//	Función:		AreaCirculo
//	Recibe:		Circunferencia circ
//	Devuelve:	Área del círculo (PI * r^2)
/******************************************************************************/

double AreaCirculo (Circunferencia circ) {
	return (PI * circ.radio * circ.radio);
}

/******************************************************************************/
//	Función:		CentroRectangulo
//	Recibe:		Rectangulo rect
//	Devuelve:	Punto2D centro (intersección de las diagonales del rectángulo)
/******************************************************************************/


Punto2D CentroRectangulo (Rectangulo rect) {
	//	Declaración de variables
	Punto2D centro;
	
	//	Cálculos
	centro.x = (rect.p_id.x + rect.p_si.x) / 2;
	centro.y = (rect.p_id.y + rect.p_si.y) / 2;
	
	//	Return
	return centro;
}

int main (void) {
	
	//	Declaración de constantes
	double RADIO_INI = 0.5, INCREMENTO = 0.25;
	
	//	Declaración de variables
	Rectangulo rect;
	Circunferencia circ;
	
	//	Entrada de datos
	cout << "Introduce los parametros del rectangulo:" << endl;
	cout << "\tEsquina superior izquierda (x, y):" << endl;
	cout << "\t\tx: ";
	cin >> rect.p_si.x;
	cout << "\t\ty: ";
	cin >> rect.p_si.y;
	
	cout << "\tEsquina inferior derecha (x, y):" << endl;
	do {
		cout << "\t\tx: ";
		cin >> rect.p_id.x;
	} while (rect.p_id.x <= rect.p_si.x);
	
	do {
		cout << "\t\ty: ";
		cin >> rect.p_id.y;
	} while (rect.p_id.y >= rect.p_si.y);
	
	//	Cálculo
	circ.centro = CentroRectangulo (rect);
	circ.radio = RADIO_INI;
	
	while (AreaCirculo (circ) < AreaRectangulo (rect)) {
		circ.radio += INCREMENTO;
	}
	
	//	Salida
	cout << endl
		  << "La circunferencia buscada esta centrada en (" << circ.centro.x
		  << ", " << circ.centro.y << ") y tiene radio " << circ.radio << endl;
	
	return 0;
}

/*
Sergio Campoy Maldonado
Fundamentos de Programaci�n
1�C

Programa que recibe los par�metros de un rect�ngulo y calcula la circunferencia
centrada en la intersecci�n de las diagonales del rect�ngulo cuya �rea es mayor
que la del rect�ngulo
*/

#include <iostream>

#include <cmath>

using namespace std;

//	Declaraci�n de constantes
const double PI = 3.14159265358979323846;

//	Registros

struct Punto2D {
	double x, y;		//	Ordenada y abscisa del punto
};

struct Rectangulo {
	Punto2D p_si;		//	Coordenada superior izquierda del rect�ngulo
	Punto2D p_id;		//	Coordenada inferior derecha del rect�ngulo
};

struct Circunferencia {
	Punto2D centro;	//	Coordenadas del centro de la circunferencia
	double radio;		//	Radio de la circunferencia
};

/******************************************************************************/
//	Funci�n:		Cuadrado
//	Recibe:		double x: N�mero que se elevar� al cuadrado
//	Devuelve:	double x*x
/******************************************************************************/

double Cuadrado (double x) {
	return (x*x);
}

/******************************************************************************/
//	Funci�n:		AreaRectangulo
//	Recibe:		Rectangulo rect
//	Devuelve:	�rea del rect�ngulo (base x altura)
/******************************************************************************/

double AreaRectangulo (Rectangulo rect) {
	//	Declaraci�n de variables
	double base, altura;
	
	//	C�lculos
	base = rect.p_id.x - rect.p_si.x;
	altura = rect.p_si.y - rect.p_id.y;
	
	//	Return
	return (base * altura);
}

/******************************************************************************/
//	Funci�n:		AreaCirculo
//	Recibe:		Circunferencia circ
//	Devuelve:	�rea del c�rculo (PI * r^2)
/******************************************************************************/

double AreaCirculo (Circunferencia circ) {
	return (PI * circ.radio * circ.radio);
}

/******************************************************************************/
//	Funci�n:		CentroRectangulo
//	Recibe:		Rectangulo rect
//	Devuelve:	Punto2D centro (intersecci�n de las diagonales del rect�ngulo)
/******************************************************************************/


Punto2D CentroRectangulo (Rectangulo rect) {
	//	Declaraci�n de variables
	Punto2D centro;
	
	//	C�lculos
	centro.x = (rect.p_id.x + rect.p_si.x) / 2;
	centro.y = (rect.p_id.y + rect.p_si.y) / 2;
	
	//	Return
	return centro;
}

int main (void) {
	
	//	Declaraci�n de constantes
	double RADIO_INI = 0.5, INCREMENTO = 0.25;
	
	//	Declaraci�n de variables
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
	
	//	C�lculo
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

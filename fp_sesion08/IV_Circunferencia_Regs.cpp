/*
Sergio Campoy Maldonado
Fundamentos de Programaci�n
1�C

Programa que:
	1)	Recibe el centro y el radio de una circunferencia y calcula la longitud de
		esta y el �rea del c�rculo.
	2)	Recibe una lista de puntos y comprueba si la circunferencia contiene a
		cada punto.
*/

#include <iostream>

#include <string>

using namespace std;

//	Declaraci�n de constantes globales
const double PI = 3.14159265358979323846;
const string TERMINADOR = "FIN";

struct Punto2D {
	double x, y;		//	Abscisa y ordenada del punto
};

struct Circunferencia {
	Punto2D centro;	//	Centro de la circunferencia (x, y)
	double radio;		//	Radio de la circunferencia
};

/******************************************************************************/
//	Funci�n:		LeeNumero
//	Recibe:		void
//	Devuelve:	Un double le�do con getline (cin, n) para evitar problemas con el
//					buffer del teclado
/******************************************************************************/

double LeeNumero () {
	string n;
	getline (cin, n);
	
	return (stod (n));
}

/******************************************************************************/
//	Funci�n:		Cuadrado
//	Recibe:		"x" un double
//	Devuelve:	"x^2", otro double
/******************************************************************************/

double Cuadrado (double x) {
	return (x*x);
}

/******************************************************************************/
//	Funci�n:		Longitud
//	Recibe:		"circ" del tipo Circunferencia
//	Devuelve:	Longitud de la circunferencia (double)
/******************************************************************************/

double Longitud (Circunferencia circ) {
	return (2 * PI * circ.radio);
}

/******************************************************************************/
//	Funci�n:		Area
//	Recibe:		"circ" del tipo Circunferencia
//	Devuelve:	�rea del c�rculo (double)
/******************************************************************************/

double Area (Circunferencia circ) {
	return (PI * circ.radio * circ.radio);
}

/******************************************************************************/
//	Funci�n:		ContienePunto
//	Recibe:		"p" Punto2D
//					"circ" Circunferencia
//	Devuelve:	"TRUE" si la circunferencia contiene a "p"
//					"FALSE" si la circunferencia NO contiene a "p"
/******************************************************************************/

bool ContienePunto (Punto2D p, Circunferencia circ) {
	double distancia_cuadrado;
	
	distancia_cuadrado = Cuadrado (circ.centro.x - p.x)
							 + Cuadrado (circ.centro.y - p.y);
	
	return (distancia_cuadrado <= Cuadrado (circ.radio));
}

int main (void) {
	//	Declaraci�n de variables
	Circunferencia circ;
	
	//	Entrada
	cout << "Introduce el centro de la circunferencia (x, y)" << endl;
	cout << "\tx: ";
	circ.centro.x = LeeNumero ();
	cout << "\ty: ";
	circ.centro.y = LeeNumero ();
	
	cout << "Introduce el radio de la circunferencia: ";
	circ.radio = LeeNumero ();
	
	//	Salida
	cout << "La longitud de la circunferencia es " << Longitud (circ) << endl;
	cout << "El area del circulo es " << Area (circ) << endl;
	
	
/******************************************************************************/
/**************************Segundo apartado************************************/
/******************************************************************************/	
	
	//	Declaraci�n de variables
	Punto2D p;
	string cad;
	
	cout << endl
		  << "Introduce un punto para comprobar si esta dentro del circulo"
		  << " (o \"FIN\" para salir)"
		  << endl;
	
	//	Lectura adelantada
	cout << "Punto: (x, y)" << endl;
	
	cout << "\tx: ";
	getline (cin, cad);
	
	while (cad != TERMINADOR) {
		p.x = stod (cad);
		
		cout << "\ty: ";
		p.y = LeeNumero ();
		
		if (ContienePunto (p, circ))
			cout << "El punto (" << p.x << ", " << p.y << ")"
				  << " SI pertenece a la circunferencia"
				  << endl;
		else
			cout << "El punto (" << p.x << ", " << p.y << ")"
				  << " NO pertenece a la circunferencia"
				  << endl;
		
		//	Lectura
		cout << "Punto: (x, y)" << endl;
	
		cout << "\tx: ";
		getline (cin, cad);
	}

	return 0;
}

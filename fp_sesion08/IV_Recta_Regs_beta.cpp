#include <iostream>
using namespace std;

struct Punto2D {
	double x, y;		//	Abcisa y ordenada de un punto
};

struct Recta {
	double A, B, C;	//	Coeficientes de la recta
};

Punto2D Interseccion (Recta s, Recta t) {
	//	Declaración de variables
	Punto2D interseccion;
	double numerador, denominador;
	
	numerador = (t.B * s.C) / s.B - t.C;
	denominador = t.A - (s.A * t.B) / s.B;
	
	interseccion.x = numerador / denominador;
	
	interseccion.y = - (s.A * interseccion.x + s.C) / s.B;
	
	return interseccion;
}

int main () {
	Recta s, t;
	Punto2D a;
	
	cout << "Introduce los parametros de la recta s: ";
	cin >> s.A >> s.B >> s.C;
	
	cout << "Introduce los parametros de la recta t: ";
	cin >> t.A >> t.B >> t.C;
	
	a = Interseccion (s, t);
	
	cout << "Las rectas intersecan en el punto (" << a.x << ", " << a.y << ")";
	cout << endl << endl;
}

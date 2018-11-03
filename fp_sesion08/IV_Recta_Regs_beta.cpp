/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que:
	1) Comprueba si dos rectas son paralelas, coincidentes o secantes. En
		el caso de que sean secantes, calcula el punto de intersección de ambas
		rectas.
	
	2) Pide puntos y comprueba si estos pertenecen a la primera recta introducida
		hasta que el usuario introduzca la cadena "FIN".
*/

#include <iostream>

#include <string>

using namespace std;

//	Tipo enumerado

enum class Posicion_relativa {
	secantes,
	paralelas,
	coincidentes
};

//	Registros

struct Punto2D {
	double x, y;		//	Abcisa y ordenada de un punto 						  (x, y)
};


struct Recta {
	double A, B, C;	//	Coeficientes de la recta					  Ax + By + C = 0
};

//	Funciones

/******************************************************************************/
//	Función:		Lee_Numero
//	Recibe:		void
//	Devuelve:	Un double leído con getline (cin, n) para evitar problemas con el
//					buffer del teclado
/******************************************************************************/

double Lee_Numero () {
	string n;
	getline (cin, n);
	
	return (stod (n));
}

/******************************************************************************/
//	Función:		Pertenece
//	Recibe:		"a": Punto en el plano cartesiano con la forma (x, y)
//					"s": Coeficientes de una recta expresada en forma cartesiana
//						  (Ax + By + C)
//	Devuelve:	TRUE: 	si el punto SÍ pertenece a la recta
//					FALSE:	si el punto NO pertenece a la recta
/******************************************************************************/

bool Pertenece (Punto2D a, Recta s) {
	return (s.A*a.x + s.B*a.y == -s.C);
}

/******************************************************************************/
//	Función:		Interseccion
//	Recibe:		"s": Coeficientes de una recta expresada en forma cartesiana
//						  (Ax + By + C)
//					"t": Coeficientes de una recta expresada en forma cartesiana
//						  (Ax + By + C)
//	Devuelve:	Punto del plano cartesiano (x,y) en el cual intersecan las rectas
/******************************************************************************/

Punto2D Interseccion (Recta s, Recta t) {
	
	//	Declaración de variables
	Punto2D interseccion;
	double numerador, denominador;
	
	//	Cálculos
	numerador = (t.B * s.C) / s.B - t.C;
	denominador = t.A - (s.A * t.B) / s.B;
	
	interseccion.x = numerador / denominador;
	
	interseccion.y = - (s.A * interseccion.x + s.C) / s.B;
	
	//	Return
	return interseccion;
}


int main (void) {
	
	//	Declaración de variables
	Recta s, t;
	Punto2D p_interseccion;
	Posicion_relativa posicion;
	
	
	
	//	Entrada
	cout << "Recta: Ax + By + C = 0"
		  << endl << endl;
	
	cout << "Introduce los parametros de la recta s: " << endl;
	
	cout << "\tA: ";
	s.A = Lee_Numero ();
	cout << "\tB: ";
	s.B = Lee_Numero ();
	cout << "\tC: ";
	s.C = Lee_Numero ();
	
	cout << endl
		  << "Introduce los parametros de la recta t: "
		  << endl;
	
	cout << "\tA: ";
	t.A = Lee_Numero ();
	cout << "\tB: ";
	t.B = Lee_Numero ();
	cout << "\tC: ";
	t.C = Lee_Numero ();
	
	
	//	Comprobación de la posición relativa de la recta
	if ((s.A / s.B) == (t.A / t.B))
		if ((s.C / s.B) == (t.C / t.B))
			posicion = Posicion_relativa::coincidentes;
		else
			posicion = Posicion_relativa::paralelas;
	else
		posicion = Posicion_relativa::secantes;
	
	
	//	Cálculo de la intersección
	if (posicion == Posicion_relativa::secantes) {
		if (s.B == 0)
			p_interseccion = Interseccion (t, s);
		else
			p_interseccion = Interseccion (s, t);
	}
	

	//	Salida
	cout << endl;
	
	switch (posicion) {
		case Posicion_relativa::coincidentes:
			cout << "Ambas rectas son coincidentes, por lo que comparten todos sus"
				  << " puntos."
				  << endl << endl;
			break;
		
		case Posicion_relativa::paralelas:
			cout << "Ambas rectas son paralelas, por lo que no comparten ningun"
				  << " punto."
				  << endl << endl;
			break;
			
		case Posicion_relativa::secantes:
			cout << "Las rectas son secantes y cortan en el punto ("
				  << p_interseccion.x << ", " << p_interseccion.y << ")."
				  << endl << endl;
			break;
	}
	
/******************************************************************************/
/*Segundo Apartado*/
/******************************************************************************/	

	//	Declaración de constantes
	const string TERMINADOR = "FIN";

	//	Declaración de variables
	string cad;
	Punto2D a;

	cout << endl
		  << "Introduce un punto para comprobar si pertenece a la recta s"
		  << " (o \"FIN\" para salir)"
		  << endl;
	
	//	Lectura adelantada
	cout << "Punto: (x, y)" << endl;
	
	cout << "\tx: ";
	getline (cin, cad);
	
	if (cad != TERMINADOR) {
		a.x = stod (cad);
		
		cout << "\ty: ";
		a.y = Lee_Numero ();
	}
	
	//	Bucle
	while (cad != TERMINADOR) {
		
		//	Comprobación y salida
		if (Pertenece (a, s))
			cout << "El punto (" << a.x << ", " << a.y
				  << ") pertenece a la recta s"
				  << endl;
		else
			cout << "El punto (" << a.x << ", " << a.y
				  << ") NO pertenece a la recta s"
				  << endl;
		
		//	Entrada
		cout << "Punto: (x, y)" << endl;
	
		cout << "\tx: ";
		getline (cin, cad);
		
		if (cad != TERMINADOR) {
			a.x = stod (cad);
			
			cout << "\ty: ";
			a.y = Lee_Numero ();
		}
	}

	return 0;
}

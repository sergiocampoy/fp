/*
Sergio Campoy Maldonado
Fundamentos de Programaci�n
1�C

Programa que:
	1)	Lee los par�metros de la funci�n gaussiana
	2)	Muestra los valores de x, g(x) y CDF(x)
	3)	Pregunta si desea continuar y vuelve a paso 1
*/

#include <iostream>

#include <cmath>

#include <iomanip>

#include <string>

using namespace std;

//	Declaraci�n de constantes globales
const double PI = 3.14159265358979323846;


struct Gaussiana {
	double x, media, desv;	//	Valor de x, media / esperanza y desviaci�n t�pica
};

/******************************************************************************/
//	Funci�n:		FuncionGaussiana
//	Recibe:		"campana" del tipo Gaussiana
//	Devuelve:	Imagen de la funci�n en el punto x (double)
/******************************************************************************/

double FuncionGaussiana (Gaussiana campana) {
	double base, exponente;
	
	base = 1 / (campana.desv * sqrt (2*PI));
	exponente = pow ((campana.x - campana.media) / campana.desv, 2) / (-2);
	
	return (base * exp (exponente));
}

/******************************************************************************/
//	Funci�n: 	FuncionCDF
//	Recibe:		"campana" del tipo Gaussiana
//	Devuelve:	�rea de la funci�n hasta el valor de x (double)

//	PRE:			campana.media = 0		(Distribuci�n normal estandar)
//					campana.desv = 1
/******************************************************************************/

double FuncionCDF (Gaussiana campana) {
	
	//	Declaraci�n de constantes
	const double b0 = 0.2316419, 	 b1 = 0.319381530,  b2 = -0.356563782,
					 b3 = 1.781477937, b4 = -1.821255978, b5 = 1.330274429;
	
	//	Declaraci�n de variables
	double w, t = 1.0 / (1 + b0 * abs (campana.x));
	
	//	C�lculos
	w = 1 - FuncionGaussiana (campana) *
		(b1*t + b2*pow(t, 2) + b3*pow(t, 3) + b4*pow(t, 4) + b5*pow(t, 5));
	
	if (campana.x < 0)
		w = (1 - w);
	
	//	Return
	return w;
}

int main () {
	cout.setf(ios::fixed);		// Notaci�n de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales
	cout << setprecision (4);	//	Precisi�n de los decimales
	
	//	Declaraci�n de variables
	Gaussiana gauss;
	bool salir = false, estandar;
	double lim_inf, lim_sup;
	string respuesta;
	
	while (!salir) {
		//	Entrada
		cout << "Introduce los parametros de la campana de Gauss: " << endl;
		cout << "\tMedia: ";
		cin >> gauss.media;
		
		do {
			cout << "\tDesviacion tipica: ";
			cin >> gauss.desv;
		} while (gauss.desv <= 0);
		
		//	C�lculos
		lim_inf = gauss.media - 3 * gauss.desv;
		lim_sup = gauss.media + 3 * gauss.desv;
		
		estandar = ((gauss.desv == 1) && (gauss.media == 0));
		
		//	Salida
		cout << "Los valores de la campana son: " << endl;
		
		for (gauss.x = lim_inf; gauss.x <= lim_sup; gauss.x += gauss.desv/2) {
			cout << "\tx = " << gauss.x;
			cout << "\tg (x) = " << FuncionGaussiana (gauss);
			
			if (estandar)
				cout << "\t\tCDF (x) = " << FuncionCDF (gauss);
			
			cout << endl;
		}
		
		if (!estandar)
			cout << endl
				  << "No se trata de la distribucion normal estandar," << endl
				  << "por lo que no se puede aplicar la aproximacion "
				  << "de Abramowitz y Stegun"
				  << endl << endl;
		
		do {
			cout << "Desea continuar? (SI / NO): ";
			cin >> respuesta;
		} while ((respuesta != "SI") && (respuesta != "NO"));
		
		if (respuesta == "NO")
			salir = true;
		
		cout << endl;
	}
	
	return 0;
}

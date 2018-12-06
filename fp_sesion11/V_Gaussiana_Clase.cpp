/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que implementa la clase Gaussiana
*/

#include <iostream>

#include <cmath>

#include <iomanip>

using namespace std;

//	Declaración de constantes globales
const double
	DELTA = 0.25,
	PI =  3.14159265359,
	b0 =  0.2316419,
	b1 =  0.319381530,
	b2 = -0.356563782,
	b3 =  1.781477937,
	b4 = -1.821255978,
	b5 =  1.330274429;


//	PRE:	desv > 0
class Gaussiana {
	private:
		double media, desv;
	
	public:
		Gaussiana (double esperanza, double desviacion)
			:	media (esperanza),
				desv (desviacion)
			{}
		
		double Valor (double x) {
			double base, exponente;
			
			base = 1.0 / (desv * sqrt (2 * PI));
			exponente = pow ((x - media) / desv, 2) / -2.0;
			
			return (base * exp (exponente));
		}
		
		double FuncionCDF (double x) {
			const double b0 = 0.2316419,
							 b1 = 0.319381530,
							 b2 =-0.356563782,
							 b3 = 1.781477937,
							 b4 =-1.821255978,
							 b5 = 1.330274429;
			double w, t;
			
			t = 1 / (1 + b0*abs(x));
			
			w = 1 - Valor (x) *
				(b1*t + b2*pow(t, 2) + b3*pow(t, 3) + b4*pow(t, 4) + b5*pow(t, 5));
			
			return ((x >= 0) ? w : (1 - w));
		}
		
		void PintaDatos () {
			for (double i = media - 3*desv; i <= media + 3*desv; i += DELTA) {
				cout << "gaussiana (" << setprecision (3) << i << ") = "
					  << setprecision (6) << Valor (i) << "\t"
					  << "CDF (" << setprecision (3) << i << ") = "
					  << FuncionCDF (i) << endl;
			}
		}
};



int main () {
	cout << fixed;
	
	
	//	Declaración de variables
	double media, desviacion;
	
	
	//	Entrada
	cout << "Introduce los parametros de la Gaussiana:" << endl
		  << "\tMedia: ";
	cin >> media;
	
	do {
		cout << "\tDesviacion tipica (positiva): ";
		cin >> desviacion;
	} while (desviacion < 0);
	
	//	Declaración de la campana de Gauss
	Gaussiana campana (media, desviacion);
	
	//	Salida
	campana.PintaDatos();
	
	return 0;
}

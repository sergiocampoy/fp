#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const double
	PI = 3.14159265359,
	GRAD_A_RAD = PI / 180,
	R = 6372797.560856;


class CoordenadasGPS {
	private:
		//	Variables privadas
		double
			longitud,
			latitud,
			altura;
		
		
		//	Métodos privados
		//	Conversión grados a radianes
		double GradARad (double grad) {
			return (grad * GRAD_A_RAD);
		}
		
		//	Conversión radianes a grados
		double RadAGrad (double rad) {
			return (rad / GRAD_A_RAD);
		}
		
		//	Comprobación de la longitud, latitud o altura introducidas
		bool EstaBienLongitud (double lon) {
			return (abs (lon) <= 180);
		}
		
		bool EstaBienLatitud (double lat) {
			return (abs (lat) <= 90);
		}
		
		bool EstaBienAltura (double h) {
			return ((h >= -423) && (h <= 8848));
		}
			
	public:
		//	Constructor
		CoordenadasGPS ()
			:	longitud (0), latitud (0), altura (0)
		{}
		
		//	Métodos SET
		void SetLongitud () {
			double lon;
			
			do {
				cout << "Introduce la longitud [-180, 180]: ";
				cin >> lon;
			} while (!EstaBienLongitud (lon));
			
			longitud = GradARad (lon);
		}
		
		void SetLatitud () {
			double lat;
			
			do {
				cout << "Introduce la latitud [-90, 90]: ";
				cin >> lat;
			} while (!EstaBienLatitud (lat));
			
			latitud = GradARad (lat);
		}
		
		void SetAltura () {
			double h;
			
			do {
				cout << "Introduce la altura [-423, 8848]: ";
				cin >> h;
			} while (!EstaBienAltura (h));
			
			altura = h;
		}
		
		//	Métodos GET
		double GetAltura () {
			return altura;
		}
		
		double LatitudGrados () {
			return (RadAGrad (latitud));
		}
		
		double LatitudRadianes () {
			return latitud;
		}
		
		double LongitudGrados () {
			return (RadAGrad (longitud));
		}
		
		double LongitudRadianes () {
			return longitud;
		}
};

double Haversine (CoordenadasGPS a, CoordenadasGPS b) {
	double z, c, d;
	z = pow (sin ((b.LatitudRadianes() - a.LatitudRadianes()) / 2.0), 2)
	  + cos (a.LatitudRadianes()) * cos (b.LatitudRadianes())
	  * pow (sin ((b.LongitudRadianes() - a.LongitudRadianes()) / 2.0), 2);
	
	c = 2 * asin (min (1.0, sqrt (z)));
	d = R * c;
	
	return d;
}

double Distancia (CoordenadasGPS a, CoordenadasGPS b) {
	double haversine, delta_h, real;
	
	haversine = Haversine (a, b);
	delta_h = a.GetAltura() - b.GetAltura();
	
	real = sqrt (haversine*haversine + delta_h*delta_h);
	
	return real;
}


int main () {
	
	
	//	Declaración de variables
	CoordenadasGPS a, b;
	double distancia, distancia_real;
	
	
	//	Entrada de datos
	cout << "Introduce los datos de dos puntos:" << endl;
	
	cout << "\tPunto a:" << endl;
	a.SetLatitud();
	a.SetLongitud();
	a.SetAltura();
	
	cout << "\tPunto b:" << endl;
	b.SetLatitud();
	b.SetLongitud();
	b.SetAltura();
	
	//	Cálculo
	distancia = Haversine (a, b);
	
	distancia_real = Distancia (a, b);
	
	//	Salida
	cout << "La distancia en el plano es " << distancia << " metros" << endl
		  << "La distnacia real es " << distancia_real << " metros" << endl;
}

/*
Sergio Campoy Maldonado
Fundamentos de Programaci�n
1�C

Programa que implementa los m�todos EsAnterior, Avanza, Retrocede, Salto y
Diferencia en la clase Instante, recibe 2 instantes y comprueba que todos los
m�todos menciona
*/

#include <iostream>

#include <cmath>

using namespace std;

//	Declaraci�n de constantes
const int
	HORAS_A_SEGUNDOS = 3600,
	HORAS_A_MINUTOS = 60,
	MINUTOS_A_SEGUNDOS = 60;

const double
	MINUTOS_A_HORAS = 1.0 / 60,
	SEGUNDOS_A_MINUTOS = 1.0 / 60,
	SEGUNDOS_A_HORAS = 1.0 / 3600;

class Instante {
	private:
		//	Datos privados
		int h;
		int min;
		int s;
	
	public:
		
		//	Constructor
		Instante ()
			:	h (0), min (0), s (0)
		{}
		
		Instante (int segundos) {
			SetSegundos (segundos);
		}
		
		//	M�todos GET
		int GetSegundos () {
			return (s + MINUTOS_A_SEGUNDOS*min + HORAS_A_SEGUNDOS*h);
		}
		
		int GetMinutos () {
			return (min + HORAS_A_MINUTOS*h);
		}
		
		string ToString () {
			string cad;
			cad = to_string (h) + "h ";
			cad += to_string (min) + "min ";
			cad += to_string (s) + "s";
			return cad;
		}
		
		//	M�todos SET
		void SetSegundos (int segundos) {
			h = segundos * SEGUNDOS_A_HORAS;
			segundos -= h * HORAS_A_SEGUNDOS;
			
			min = segundos * SEGUNDOS_A_MINUTOS;
			segundos -= min * MINUTOS_A_SEGUNDOS;
			
			s = segundos;
		}
		
		void SetTiempo () {
			int horas;
			int minutos;
			int segundos;
			
			do {
				cout << "Introduce el numero de horas: ";
				cin >> horas;
			} while (horas < 0);
			
			do {
				cout << "Introduce el numero de minutos: ";
				cin >> minutos;
			} while (minutos < 0);
			
			do {
				cout << "Introduce el numero de segundos: ";
				cin >> segundos;
			} while (segundos < 0);
			
			segundos += horas * HORAS_A_SEGUNDOS + minutos * MINUTOS_A_SEGUNDOS;
			
			SetSegundos (segundos);
		}
		
		//	true:  this anterior a otro
		//	false: otro anterior a this
		bool EsAnterior (Instante otro) {
			return (GetSegundos() < otro.GetSegundos());
		}
		
		Instante Avanza (Instante otro) {
			//	Utiliza el constructor con argumentos
			Instante nuevo (GetSegundos() + otro.GetSegundos());
			return nuevo;
		}
		
		Instante Retrocede (Instante otro) {
			//	Utiliza el constructor con argumentos
			Instante nuevo (GetSegundos() - otro.GetSegundos());
			return nuevo;
		}
		
		Instante Salto (int num_segundos) {
			//	Utiliza el constructor con argumentos
			Instante nuevo (GetSegundos() + num_segundos);
			return nuevo;
		}
		
		Instante Diferencia (Instante otro) {
			//	Utiliza el constructor con argumentos
			Instante nuevo (abs(GetSegundos() - otro.GetSegundos()));
			return nuevo;
		}
};

int main () {
	
	int segundos;
	
	//	Declaraci�n de objetos
	Instante a, b, aux;
	
	//	Entrada
	cout << "Introduce los datos de un instante:" << endl;
	a.SetTiempo();
	
	cout << "Introduce los datos del otro instante:" << endl;
	b.SetTiempo();
	
	//	C�lculo
	if (a.EsAnterior(b))
		cout << endl
			  << "El instante " << a.ToString()
			  << " es anterior a " << b.ToString()
			  << endl;
	else
		cout << endl
			  << "El instante " << b.ToString()
			  << " es anterior a " << a.ToString()
			  << endl;
	
	aux = a.Avanza (b);
	
	cout << "Al avanzar " << b.ToString() << " desde el instante "
		  << a.ToString() << " el instante obtenido es " << aux.ToString()
		  << endl;
	
	aux = a.Retrocede(b);
	
	cout << "Al retroceder " << b.ToString() << " desde el instante "
		  << a.ToString() << " el instante obtenido es " << aux.ToString()
		  << endl;

	do {
		cout << "Cuantos segundos quieres avanzar? ";
		cin >> segundos;
	} while (segundos < 0);
	
	aux = a.Salto(segundos);
	
	cout << "Al avanzar " << segundos << " segundos desde el instante "
		  << a.ToString() << " el instante obtenido es " << aux.ToString()
		  << endl;
	
	aux = a.Diferencia(b);
	
	cout << "La diferencia de tiempo entre "
		  << a.ToString() << " y " << b.ToString() <<  " es " << aux.ToString()
		  << endl;

	return 0;
}

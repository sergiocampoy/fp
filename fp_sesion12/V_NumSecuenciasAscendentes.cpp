/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que implementa en la clase SecuenciaEnteros un método que cuenta el
número de secuencias ascendentes
*/

#include <iostream>

#include <string>
using namespace std;

class SecuenciaEnteros {

	private:
		//	Datos privados
		static const int SIZE = 50;
		int secuencia [SIZE];
		int usados;

	public:
		//	Constructor sin argumentos
		SecuenciaEnteros ():
			usados (0)
		{}
		
		//	Métodos públicos
		int GetUsados () {
			return usados;
		}
		
		int GetSize () {
			return SIZE;
		}
		
		void Reset () {
			usados = 0;
		}
		
		//	PRE: usados < SIZE
		void Add (int n) {
			if (usados < SIZE) {
				secuencia [usados] = n;
				usados++;
			}
		}
		
		//	PRE: 0 <= n < usados
		int Elemento (int n) {
			return secuencia [n];
		}
		
		//	PRE: 0 <= pos < usados
		void Cambia (int pos, int n) {
			if (pos < usados) {
				secuencia [pos] = n;
			}
		}
		
		//	PRE: 0 <= pos < usados
		void Elimina (int pos) {
			if ((0 <= pos) && (pos < usados)) {
				for (int i = pos; i < usados - 1; i++)
					secuencia [pos] = secuencia [pos + 1];
				usados--;
			}
		}
		
		//	PRE: usados < SIZE
		//		  0 <= pos < usados
		void Inserta (int pos, int n) {
			if ((0 <= pos) && (pos < usados) && (usados < SIZE)) {
				for (int i = usados; i > pos; i--) {
					secuencia [i] = secuencia [i - 1];
				}
				secuencia [pos] = n;
			}
		}
		
		string ToString () {
			string cad;
			
			cad = "{" + to_string (secuencia [0]);
			for (int i = 1; i < usados; i++)
				cad += ", " + to_string (secuencia [i]);
			cad += "}";
			
			return cad;
		}
		
		int GetNumSecuenciasAscendentes () {
			int rachas = 1;

			for (int i = 1; i < usados; i++)
				if (secuencia [i] < secuencia [i - 1])
					rachas++;
			
			
			return rachas;
		}
};



int main () {

	//	Constructor sin argumentos
	SecuenciaEnteros sec;


	//	Recibe la secuencia de enteros
	int total, n;
	
	cout << "Cuantos numeros se van a introducir (<50)? ";
	cin >> total;
	
	for (int i = 0; i < total; i++) {
		cin >> n;
		sec.Add(n);
	}
	
	
	//	Muestra cadena original
	cout << "La cadena original es:" << endl
		  << sec.ToString()
		  << endl;
	
	
	//	Muestra el número de secuencias ascendentes
	cout << "El numero de rachas es " << sec.GetNumSecuenciasAscendentes()
		  << endl;

	return 0;
}

/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que implementa el método EliminaMayusculas en la clase Secuencia
*/

#include <iostream>

#include <cctype>

using namespace std;

const int SIZE = 100;

class Secuencia {	
	private:
		//	Datos privados
		char secuencia [SIZE];
		int usados;
		
		//	Métodos privados
		
		//	PRE:	cad.length < SIZE (100)
		void StringToSecuencia (string cad) {
			if (cad.length() <= SIZE)
				for (int i = 0; i < cad.length(); i++)
					secuencia [i] = cad.at(i);
		}
	
	public:
		//	Constructor con argumentos
		
		//	PRE:	cad.length < SIZE (100)
		Secuencia (string cad)
		:	usados (cad.length())
		{
			StringToSecuencia (cad);
		}
		
		//	Métodos públicos
		void EliminaOcurrencias (char a_borrar) {
			int	//	Apuntadores
				pos_lectura = 0,
				pos_escritura = 0;
			
			while (pos_lectura < usados) {
				if (secuencia [pos_lectura] != a_borrar) {
					secuencia [pos_escritura] = secuencia [pos_lectura];
					pos_escritura++;
				}
				pos_lectura++;
			}
			usados = pos_escritura;
		}
		
		void EliminaRepetidos () {
			int	//	Apuntadores
				pos_lectura = 0,
				pos_escritura = 0;
			bool repetido;
			
			while ((pos_lectura < usados)) {
				repetido = false;
				for (int i = 0; (i < pos_escritura) && !repetido; i++)
					repetido = (secuencia [pos_lectura] == secuencia [i]);

				if (!repetido) {
					secuencia [pos_escritura] = secuencia [pos_lectura];
					pos_escritura++;
				}

				pos_lectura++;
			}
			
			usados = pos_escritura;
		}
		
		//	PRE:	0 <= n < usados
		void EliminaHasta (int n) {
			if ((n >= 0) && (n < usados)) {
				for (int i = n + 1; i < usados; i++) {
					secuencia [i - n - 1] = secuencia [i];
				}
				usados -= n + 1;
			}
		}
		
		//	PRE:	0 <= n < usados
		void EliminaDesde (int n) {
			usados = n;
		}
		
		string GetCadena () {	//	Método ToString
			string cad;
			for (int i = 0; i < usados; i++) {
				cad += secuencia [i];
			}
			return cad;
		}
		
		int GetUsados () {
			return usados;
		}
		
		void EliminaExcesoBlancos () {
			for (int i = 0; i < usados; i++)
				if (isspace (secuencia [i]))
					while (isspace (secuencia [i + 1]))
						Elimina (i + 1);
		}
		
		//	PRE: 0 <= pos < usados
		void Elimina (int pos) {
			if ((0 <= pos) && (pos < usados)) {
				for (int i = pos; i < usados - 1; i++)
					secuencia [i] = secuencia [i + 1];
				usados--;
			}
		}
		
		void EliminaMayusculas () {
			int	//	Apuntadores
				pos_lectura = 0,
				pos_escritura = 0;
			
			while (pos_lectura < usados) {
				if (('A' > secuencia [pos_lectura])
				|| (secuencia [pos_lectura] > 'Z')) {
					secuencia [pos_escritura] = secuencia [pos_lectura];
					pos_escritura++;
				}
				pos_lectura++;
			}
			usados = pos_escritura;
		}
};

int main () {
	//	Entrada
	string cad;
	cout << "Introduce una cadena de caracteres:" << endl;
	getline (cin, cad);
	
	//	Constructor con argumentos
	Secuencia secuencia (cad);
	
	//	Muestra la cadena original
	cout << "\"" << secuencia.GetCadena() << "\"" << endl;
	
	//	Borra las mayúsculas
	secuencia.EliminaMayusculas ();
	
	//	Muestra la nueva cadena sin mayusculas
	cout << "La cadena sin mayusculas es:" << endl
		  << "\"" << secuencia.GetCadena() << "\"" << endl;
	
	return 0;
}

/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que implementa mediante clases un método para eliminar los caracteres
repetidos en una cadena de caracteres
*/

#include <iostream>

#include <string>

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
		
		string GetCadena () {	//	Método ToString
			string cad;
			for (int i = 0; i < usados; i++) {
				cad += secuencia [i];
			}
			return cad;
		}
};

int main () {
	
	//	Recibe la cadena
	string cad;
	do {
		cout << "Introduce una cadena (longitud < 100):" << endl;
		getline (cin, cad);
	} while ((cad.length() <= 0) || (cad.length() > SIZE));


	//	Constructor
	Secuencia texto (cad);
	
	
	//	Muestra cadena original
	cout << "La cadena original es:" << endl
		  << "\"" << texto.GetCadena() << "\""
		  << endl;


	//	Elimina los repetidos
	texto.EliminaRepetidos ();
	
	
	//	Muestra la nueva cadena
	cout << "La cadena sin repetidos es:" << endl
		  << "\"" << texto.GetCadena() << "\""
		  << endl;
	
	
	return 0;
}

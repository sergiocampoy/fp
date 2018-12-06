/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que:
	1)	Lee y almacena en una matriz hasta 20 secuencias de 50 caracteres
	2)	Muestra las secuencias
	3)	Codifica las secuencias mediante RLE y las guarda en otra matriz
	4)	Muestra las secuencias codificadas
	5)	Descodifica las secuencias y las guarda en otra matriz
	6) Muestra las secuencias reconstruidas
	7)	Compara las secuencias iniciales y finales
*/

#include <iostream>

#include <string>

using namespace std;

struct pareja {		//	Pareja de datos en RLE
	int repeticiones;	//	nº de veces que se repite el caracter
	char caracter;		// caracter que se repite
};

int main (void) {
	
	//	Declaración de constantes
	const char NULO = 00;
	const pareja TERMINADOR_PAREJA = {-1, NULO};
	const string TERMINADOR = "FIN";
	const int COLUMNAS = 50;
	const int FILAS = 20;
	
	
	//	Declaración de matrices
	char m [COLUMNAS + 1] [FILAS];
	pareja m_codificada [COLUMNAS + 1] [FILAS];
	char m_reconstruida [COLUMNAS + 1] [FILAS];
	
	
	//	Declaración de variables
	int usados = 0;
	bool salir = false;
	
	
	//	Entrada
	for (int i = 0; (i < FILAS) && !salir; i++) {
		
		string cad;
		
		//	Lectura del string cad
		do {
			getline (cin, cad);
		} while ((cad.length() == 0) || (cad.length() > COLUMNAS));
		
		// Conversión string a matriz
		if ((cad == TERMINADOR) || (usados >= FILAS))
			salir = true;
	
		else {
			usados++;
			
			int j = 0;
			
			while (j < cad.length()) {
				m [j] [i] = cad.at(j);
				j++;
			}
			
			m [j] [i] = NULO;		//	Añade NULL al final de la fila para poder
										//	identificar cuando acaba
		}
	}
	
	
	//	Salida m
	cout << endl
		  << "Las secuencias introducidas son:"
		  << endl << endl;
	
	for (int i = 0; i < usados; i++) {
		
		int j = 0;
		
		while (m [j] [i] != NULO) {
			cout << m [j] [i];
			j++;
		}
		
		cout << endl;
	}


	//	Codificación de m
	for (int i = 0; i < usados; i++) {
		//	Declaración de variables locales
		int j = 1;
		int repeticiones = 1;
		int posicion = 0;
//		pareja a;
		
		//	Codificación
		while (m [j - 1] [i] != NULO) {
			
			if (m [j] [i] == m [j - 1] [i])
				repeticiones++;
				
			else {
//				a = {repeticiones, m [j - 1] [i]};
				m_codificada [posicion] [i] = {repeticiones, m [j - 1] [i]};
				posicion++;
				repeticiones = 1;
			}
			j++;
		}
		m_codificada [posicion] [i] = TERMINADOR_PAREJA;
	}


	//	Salida de m_codificada
	cout << endl
		  << "Las secuencias codificadas son:"
		  << endl << endl;
	
	for (int i = 0; i < usados; i++) {
		//	Declaración de variables locales
		int j = 0;
		pareja a = m_codificada [j] [i];
		
		while (a.repeticiones != TERMINADOR_PAREJA.repeticiones) {
			cout << a.repeticiones << "-" << a.caracter << ", ";
			j++;
			a = m_codificada [j] [i];
		}
		cout << endl;
	}


	//	Descodificación de m_codificada
	for (int i = 0; i < usados; i++) {
		
		//	Declaracción de variables locales
		int j = 0;
		int posicion = 0;
		pareja a = m_codificada [j] [i];

		while (a.repeticiones != TERMINADOR_PAREJA.repeticiones) {
			
			for (int k = 0; k < a.repeticiones; k++)
				m_reconstruida [posicion + k] [i] = a.caracter;
			
			posicion += a.repeticiones;
			j++;
			a = m_codificada [j] [i];
		}
		m_reconstruida [posicion] [i] = NULO; 
	}
	
	//	Salida de m_reconstruida
	cout << endl
	 	  << "Las secuencias reconstruidas son:"
	 	  << endl << endl;
	
	for (int i = 0; i < usados; i++) {
		
		int j = 0;
		
		while (m_reconstruida [j] [i] != NULO) {
			cout << m_reconstruida [j] [i];
			j++;
		}
		cout << endl;
	}
	cout << endl;
	
	
	//	Comparación de m con m_reconstruida
	bool igual = true;
	for (int i = 0; (i < usados) && igual; i++)
	
		for (int j = 1; (m [j - 1] [i] != NULO) && igual; j++)
		
			if (m [j] [i] != m_reconstruida [j] [i])
			
				igual = false;


	//	Resultado de la comparación
	switch (igual) {
		
		case true:
			if (usados == 0)
				cout << "No se ha introducido ningun dato" << endl;
				
			else
				cout << "Las matrices son iguales" << endl;
			break;
			
		case false:
			cout << "Las matrices son distintas" << endl;
			break;
	}
}

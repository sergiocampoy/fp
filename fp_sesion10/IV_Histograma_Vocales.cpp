/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que cuenta el número de veces que aparece cada vocal y muestra los
resultados en forma de histograma
*/

#include <iostream>

#include <cctype>

#include <iomanip>

using namespace std;

int main (void) {
	
	//	Declaración de constantes
	const char TERMINADOR = '*';
	const int N_VOCALES = 5;
	const int MAX_REPETICIONES = 500;
	
	//	Casilla a la que pertenece cada vocal
	const int A = 0;
	const int E = 1;
	const int I = 2;
	const int O = 3;
	const int U = 4;


	//	Declaración del vector de frecuencias
	int frecuencia [N_VOCALES] = {0};
	
	
	//	Declaración de la matriz histograma
	bool m [N_VOCALES] [MAX_REPETICIONES] = {false}; // true -> '*', false -> ' '
	
	
	//	Lectura
	char c;
	c = cin.get();
	
	while (c != TERMINADOR) {
		c = toupper (c);
		
		switch (c) {
			case 'A':
				frecuencia [A]++;
			break;
			
			case 'E':
				frecuencia [E]++;
			break;
			
			case 'I':
				frecuencia [I]++;
			break;
			
			case 'O':
				frecuencia [O]++;
			break;
			
			case 'U':
				frecuencia [U]++;
			break;
		}
		c = cin.get();
	}


	//	Cálculo de la vocal con mayor frecuencia
	int max = frecuencia [0];
	
	for (int i = 1; i < N_VOCALES; i++)
		if (frecuencia [i] > max)
			max = frecuencia [i];


	//	Cálculo de la matriz histograma
	for (int i = 0; i < N_VOCALES; i++)
		for (int j = 0; j < frecuencia [i]; j++)
			m [i] [j] = true;


	//	Salida (sin marco)
	cout << endl;
	for (int j = max; j > 0; j--) {
		
		cout << setw (3) << j;
		
		for (int i = 0; i < N_VOCALES; i++)
			m [i] [j - 1] ? cout << " *" : cout << "  ";

		cout << endl;
	}
	
	cout << "    a e i o u" << endl;


//	Versión con marco (y muchos literales)

/*	
	cout << endl << (char) (201);
	for (int i = 0; i < 14; i++)
		cout << (char) (205);
	cout << (char) (187) << endl;
	
	for (int j = max; j > 0; j--) {
		
		cout << (char) (186) << setw (3) << j;
		
		for (int i = 0; i < N_VOCALES; i++)
			m [i] [j - 1] ? cout << " *" : cout << "  ";

		cout << " " << (char) (186) << endl;
	}
	
	cout << (char) (186) << "    a e i o u " << (char) (186) << endl;
	
	cout << (char) (200);
	for (int i = 0; i < 14; i++)
		cout << (char) (205);
	cout << (char) (188) << endl;
*/

	return 0;
}

/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que lee un número indeterminado de caracteres y devuelve el número de
apariciones de cada letra y el número total de caracteres introducidos
*/

#include <iostream>

#include <cctype>

using namespace std;

//	Declaración de constantes
const char DELTA = 'A';
const char TERMINADOR = '*';
const int ELEMENTOS = 'Z' - 'A' + 1;

int main (void) {
	
	//	Declración de variables
	long contador = 0;
	int n_caracteres [ELEMENTOS] = {0};
	char caracter;
	
	//	Entrada adelantada
	caracter = cin.get();

	while (caracter != TERMINADOR) {
		contador++;
		
		if (isalpha (caracter)) {
			caracter = toupper (caracter);
			n_caracteres [caracter - DELTA]++;
		}

		//	Entrada
		caracter = cin.get();
	}
	
	//	Salida
	for (int i = 0; i < ELEMENTOS; i++) {
		cout << "Se han contado " << n_caracteres [i] << " " << (char) (i + DELTA)
			  << endl;
	}
	
	cout << endl
		  << "Se han introducido " << contador << " caracteres en total"
		  << endl << endl;
	
	
	return 0;
}

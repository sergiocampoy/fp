/*
Sergio Campoy Maldonado
Fundamentos de Programaci�n
1�C

Programa que recibe una serie de caracteres y determina si se trata de un
pal�ndromo o no
*/

#include <iostream>

using namespace std;

int main (void) {
	
	//	Declaraci�n de constantes
	const int TAMANIO = 100;
	const char TERMINADOR = '*';
	
	
	//	Declaraci�n de variables
	char caracter;
	int iteraciones = 0;
	bool palindromo = true;
	
	
	//	Declaraci�n del vectores
	char cadena [TAMANIO];
	
	
	//	Lectura anticipada
	caracter = cin.get();
	
	
	//	Entrada de datos al vector
	while ((caracter != TERMINADOR) && (iteraciones < TAMANIO)) {
		cadena [iteraciones] = caracter;
		
		iteraciones ++;
		
		caracter = cin.get();
	}
	
	
	//	Comprobaci�n de si es pal�ndromo o no
	int i = 0;
	while ((i < iteraciones) && palindromo) {
		(cadena[i] == cadena[iteraciones - i - 1]) ? i++ : palindromo = false;
	}
	
	
	//	Salida
	if (palindromo)
		cout << endl
			  << "La cadena introducida SI es un palindromo"
			  << endl << endl;
	else
		cout << endl
			  << "La cadena introducida NO es un palindromo"
			  << endl << endl;
	
	
	return 0;
}

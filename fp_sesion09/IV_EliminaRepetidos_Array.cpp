/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que lee una serie de números positivos (acaba al introducir un numero
negativo) y elimina del vector los valores repetidos, dejando una sola copia.
	1)	Utilizando dos vectores
	2)	Utilizando un vector
	3)	Utilizando un vector y dos apuntadores
*/

#include <iostream>

using namespace std;

int main (void) {
	
	//	Declaración de constantes
	const int SIZE = 50;
	
	//	Declaración de variables
	int vector [SIZE];
	int sin_repetidos [SIZE];
	int usados, usados2;
	
/******************************************************************************/
//	PRIMER APARTADO
//	Utilizando dos vectores

	//	Entrada
	cout << "PRIMERA IMPLEMENTACION:"
		  << endl
		  << "Introduce numeros positivos (negativo para terminar)"
		  << endl;

	usados = 0;
	cin >> vector [usados];
	
	while ((usados < SIZE) && (vector [usados] >= 0)) {
		usados++;
		
		cin >> vector [usados];	
	}
	

	//	Cálculo
	usados2 = 0;
	sin_repetidos [0] = vector [0];
	usados2++;
	
	for (int i = 1; i < usados; i++) {
		if (vector [i] != vector [i - 1]) {
			sin_repetidos [usados2] = vector [i];
			usados2++;
		}
	}
	
	//	Salida
	cout << "El nuevo vector sin numeros repetidos es:" << endl;
	
	for (int i = 0; i < usados2; i++) {
		cout << "\t" << sin_repetidos [i] << endl;
	}
	
/******************************************************************************/
//	PRIMER APARTADO
//	Utilizando un vector
	
	//	Entrada
	cout << endl
		  << "SEGUNDA IMPLEMENTACION:"
		  << endl
		  << "Introduce numeros positivos (negativo para terminar)"
		  << endl;
	
	usados = 0;
	cin >> vector [usados];
	
	while ((usados < SIZE) && (vector [usados] >= 0)) {
		usados++;
		
		cin >> vector [usados];	
	}
	
	
	//	Cálculo
	for (int i = 1; i < usados; i++) {
		if (vector [i] == vector [i - 1]) {
			usados--;
			for (int j = i; j < usados; j++) {
				vector [j] = vector [j + 1];
			}
		}
	}
	
	
	//	Salida
	cout << "El nuevo vector sin numeros repetidos es:" << endl;
	
	for (int i = 0; i < usados; i++) {
		cout << "\t" << vector [i] << endl;
	}
	
/******************************************************************************/
//	PRIMER APARTADO
//	Utilizando un vector y dos apuntadores

	//	Entrada
	cout << endl
		  << "TERCERA IMPLEMENTACION:"
		  << endl
		  << "Introduce numeros positivos (negativo para terminar)"
		  << endl;
	
	usados = 0;
	cin >> vector [usados];
	
	while ((usados < SIZE) && (vector [usados] >= 0)) {
		usados++;
		
		cin >> vector [usados];	
	}
	
	
	//	Cálculo
	int posicion_lectura = 1, posicion_escritura = 1;
	
	while (posicion_lectura < usados) {
		if (vector [posicion_lectura] == vector [posicion_lectura - 1]) {
			posicion_lectura++;
		}
		else {
			vector [posicion_escritura] = vector [posicion_lectura];
			posicion_escritura++;
			posicion_lectura++;
		}
	}
	
	
	//	Salida
	cout << "El nuevo vector sin numeros repetidos es:" << endl;
	
	for (int i = 0; i < posicion_escritura; i++) {
		cout << "\t" << vector [i] << endl;
	}
	
	return 0;
}

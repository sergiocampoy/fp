/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que recibe un string, lo codifica usando el método RLE y lo vuelve a
descodificar
*/

#include <iostream>

#include <string>

using namespace std;

int main (void) {
	
	//	Declaración de constantes
	const int SIZE = 50;
	
	//	Declaración de variables
	string cad;
	char s [SIZE];
	string s_codificada [2*SIZE];
	char s_reconstruida [SIZE];
	int usado;
	int repeticiones;
	int posicion;
	
	//	Entrada
	do {
		cout << "Introduce una cadena de caracteres (no mas de 50):" << endl;
		getline (cin, cad);
	} while ((cad.length() == 0) || (cad.length() > SIZE));
	
	usado = cad.length();
	
	for (int i = 0; i < usado; i++) {
		s [i] = cad.at(i);
	}
	
	//	Salida de la secuencia original
	cout << endl
		  << "La secuencia original es: \"";
	
	for (int i = 0; i < usado; i++) {
		cout << s [i];
	}
	
	cout << "\"" << endl;
	
	//	Codificación de la secuencia original
	repeticiones = 1;
	posicion = 0;
	
	for (int i = 1; i <= usado; i++) {
		if (s [i] == s [i - 1]) {
			repeticiones++;
		}
		else {
			s_codificada [posicion] = to_string (repeticiones);
			s_codificada [posicion + 1] = s [i - 1];
			posicion += 2;
			repeticiones = 1;
		}
	}
	
	//	Salida de la secuencia codificada
	cout << endl
		  << "La secuencia codificada es: \"";
	
	for (int i = 0; i < posicion; i++) {
		cout << s_codificada [i];
	}
	cout << "\"" << endl;

	
	//	Decodificación de la secuencia
	int contador = 0;
	
	for (int i = 0; i < posicion; i += 2) {
		for (int j = 0; j < stoi (s_codificada [i]); j++)
			s_reconstruida [j + contador] = (s_codificada [i + 1]).at(0);
		
		contador += stoi (s_codificada [i]);
	}

	//	Salida de la secuencia reconstruida
	cout << endl
		  << "La secuencia codificada descodificada es \"";
	
	for (int i = 0; i < usado; i++) {
		cout << s [i];
	}
	
	cout << "\"" << endl;
	
	
	//	Comparación de las secuencias iniciales y reconstruidas
	bool igual = true;
	
	for (int i = 0; (i < usado) && igual; i++)
		igual = (s [i] == s_reconstruida [i]);
	
	if (igual)
		cout << endl
		 	  << "s y s_reconstruida son iguales"
		 	  << endl << endl;
	else
		cout << endl
			  << "s y s_reconstruida NO son iguales"
			  << endl << endl;
	
	return 0;
}

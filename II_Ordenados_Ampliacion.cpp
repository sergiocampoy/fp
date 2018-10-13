/*
Sergio Campoy Maldonado, Fundamentos de Programaci�n 1�C

Programa que detecta si 3 n�meros est�n ordenados de forma ascendente,
descendente, o no est�n ordenados
*/

#include <iostream>

using namespace std;

enum Orden
		{ascendente, descendente, desordenado};

int main () {
	//	Declaraci�n de variables
	int a, b, c;
	Orden abc;
	
   // Entrada de datos
   cout << "Introduce 3 numeros enteros (a b c): ";
   cin >> a >> b >> c;

   // C�lculos
   if ((a < b) && (b < c))
   	abc = Orden::ascendente;
   else if ((a > b) && (b > c))
   	abc = Orden::descendente;
   else
   	abc = Orden::desordenado;
   
   
   switch (abc) {
		case Orden::ascendente:
			cout << endl
				  << "Est�n ordenados en orden ascendente"
				  << endl << endl;
			break;
		
		case Orden::descendente:
			cout << endl
				  << "Est�n ordenados en orden descendente"
				  << endl << endl;
			break;
		
		case Orden::desordenado:
			cout << endl
				  << "No est�n ordenados"
				  << endl << endl;
			break;
	}
}

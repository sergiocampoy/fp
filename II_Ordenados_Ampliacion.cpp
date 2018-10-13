/*
Sergio Campoy Maldonado, Fundamentos de Programación 1ºC

Programa que detecta si 3 números están ordenados de forma ascendente,
descendente, o no están ordenados
*/

#include <iostream>

using namespace std;

enum Orden
		{ascendente, descendente, desordenado};

int main () {
	//	Declaración de variables
	int a, b, c;
	Orden abc;
	
   // Entrada de datos
   cout << "Introduce 3 numeros enteros (a b c): ";
   cin >> a >> b >> c;

   // Cálculos
   if ((a < b) && (b < c))
   	abc = Orden::ascendente;
   else if ((a > b) && (b > c))
   	abc = Orden::descendente;
   else
   	abc = Orden::desordenado;
   
   
   switch (abc) {
		case Orden::ascendente:
			cout << endl
				  << "Están ordenados en orden ascendente"
				  << endl << endl;
			break;
		
		case Orden::descendente:
			cout << endl
				  << "Están ordenados en orden descendente"
				  << endl << endl;
			break;
		
		case Orden::desordenado:
			cout << endl
				  << "No están ordenados"
				  << endl << endl;
			break;
	}
}

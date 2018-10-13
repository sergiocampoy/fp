#include <iostream>
using namespace std;

int main () {
	//	Declaración de variables
	double capital_inicial, capital, interes;
	int years;
	
	//	Entrada de datos
	do {
		cout << "Introduce el capital: ";
		cin >> capital_inicial;
	} while (capital_inicial < 0);
	
	do {
		cout << "Introduce el interes: ";
		cin >> interes;
	} while ((interes <= 0) || (interes > 10));
	
	//	Cálculos
	capital = capital_inicial;
	while (capital < 2 * capital_inicial) {
		capital = capital + capital * interes / 100;
		years++;
	}
	
	//	Salida
	cout << endl
		  << "Han de pasar " << years << " anyos para que el capital se duplique"
		  << endl << endl;
}

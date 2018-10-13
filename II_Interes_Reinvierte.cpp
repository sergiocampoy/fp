/*
Sergio Campoy Maldonado, Fundamentos de Programación 1ºC
Programa que calcula la ganancia al invertir un capital con un interés durante
un número de años elegido por el usuario
	Entrada: capital, interes, nº de años que invierte seguidos
	
	Salida: Todas las ganancias de cada año
*/

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
	
	do {
		cout << "Introduce el numero de anyos que se va a reinvertir: ";
		cin >> years;
	} while ((years < 1) || (years > 20));
	
	//	Cálculos
	int i = 0;	//	Variable contador
	capital = capital_inicial;
	while (i < years) {
		capital = capital + capital * interes / 100;
		i++;
		cout << "Total en el anyo numero " << i << " = " << capital
			  << endl;
	}
}

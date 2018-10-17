/*
Sergio Campoy Maldonado, Fundamentos de Programación 1ºC

Programa que recibe una serie de temperaturas y calcula cuándo se produce la
mayor serie de temperaturas crecientes consecutiva y su longitud
*/

#include <iostream>

using namespace std;

int main () {
	//	Declaración de constantes
	const double Terminador = -1;
	
	//	Declaración de variables
	double temp, temp_anterior;
	double temp_inicio_racha, posible_temp_inicio_racha, temp_final_racha;
	int contador = 1, comienzo_racha, racha;
	int comienzo_mejor_racha, mejor_racha = 0;
	bool fin_prematuro = false;
	
	//	Entrada anticipada
	cin >> temp;
	if (temp == -1)
		fin_prematuro = true;
	else
		temp_anterior = temp;
	
	while ((temp != Terminador) && !fin_prematuro) {
		if (temp > temp_anterior) {
			racha++;
		}
		else {
			comienzo_racha = contador;
			racha = 1;
			posible_temp_inicio_racha = temp;
		}
		
		if (racha > mejor_racha) {
			comienzo_mejor_racha = comienzo_racha;
			mejor_racha = racha;
			temp_inicio_racha = posible_temp_inicio_racha;
			temp_final_racha = temp;
		}
		
		contador++;		
		temp_anterior = temp;
		cin >> temp;
	}
	
	//	Salida
	if (fin_prematuro) {
		cout << endl
			  << "Error. No se ha introducido ninguna temperatura"
			  << endl << endl;
	}
	else if (mejor_racha == 1) {
		cout << endl
			  << "La temperatura no aumenta en ningun momento"
			  << endl << endl;
	}
	else {
		cout << endl
			  << "La mayor subsecuencia empieza en la posicion "
			  << comienzo_mejor_racha << " con temperatura " << temp_inicio_racha
			  << " y tiene longitud "
			  << mejor_racha << " con temperatura " << temp_final_racha
			  << endl << endl;
	}
}

/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que recibe una lista de matrículas con su correspondiente velocidad y
el tipo de radar que las captó y devuelve la máxima velocidad imputada junto a
su matrícula, esta vez usando funciones.
*/

#include <iostream>

#include <string>

#include <cctype>

using namespace std;

//	Declaración de constantes globales
const string TERMINADOR = "FIN";
const double VEL_LIMITE = 100;
const double ERROR_FIJO_MENOR = 5;
const double ERROR_FIJO_MAYOR = 0.05;
const double ERROR_MOVIL_MENOR = 7;
const double ERROR_MOVIL_MAYOR = 0.07;


double Velocidad_imputada (double vel_captada, char radar) {
	
	//	Declaración de variables
	double vel_imputada;
	
	//	Cálculos
	if (radar == 'F') {
		if (vel_captada < VEL_LIMITE)
			vel_imputada = vel_captada - ERROR_FIJO_MENOR;
		else
			vel_imputada = vel_captada * (1 - ERROR_FIJO_MAYOR);
	}
	else if (radar == 'M') {
		if (vel_captada < VEL_LIMITE)
			vel_imputada = vel_captada - ERROR_MOVIL_MENOR;
		else
			vel_imputada = vel_captada * (1 - ERROR_MOVIL_MAYOR);
	}
	
	//	Return
	return vel_imputada;
}

int main (void) {
	
	//	Declaración de variables
	string matricula, matricula_vel_max;
	string lectura;
	char radar;
	double vel_captada, vel_imputada, vel_max = 0;
	bool fin_prematuro = false;
	
	//	Entrada adelantada
	cout << "Introduce la matricula: ";
	getline (cin, matricula);
	
	if (matricula != TERMINADOR) {
		do {
			cout << "Introduce el tipo de radar: ";
			getline (cin, lectura);
			radar = toupper (lectura.at (0));
		} while ((radar != 'F') && (radar != 'M'));
		
		do {
			cout << "Introduce la velocidad (>10km/h): ";
			getline (cin, lectura);
			vel_captada = stod (lectura);
		} while (vel_captada < 10);
	}
	else
		fin_prematuro = true;
	
	while (matricula != TERMINADOR) {
		vel_imputada = Velocidad_imputada (vel_captada, radar);
		
		//	Asignación de la velocidad máxima
		if (vel_imputada > vel_max) {
			vel_max = vel_imputada;
			matricula_vel_max = matricula;
		}

		cout << "Introduce la matricula: ";
		getline (cin, matricula);

		if (matricula != TERMINADOR) {
			do {
				cout << "Introduce el tipo de radar: ";
				getline (cin, lectura);
				radar = toupper (lectura.at (0));
			} while ((radar != 'F') && (radar != 'M'));

			do {
				cout << "Introduce la velocidad (>10km/h): ";
				getline (cin, lectura);
				vel_captada = stod (lectura);
			} while (vel_captada < 10);
		}
	}
	
	//	Salida
	if (fin_prematuro)
		cout << endl
			  << "No se ha introducido ningun dato."
			  << endl << endl;
	else
		cout << endl
			  << "La velocidad mayor ha sido " << vel_max
			  << " km/h con matricula " << matricula_vel_max
			  << endl << endl;
}

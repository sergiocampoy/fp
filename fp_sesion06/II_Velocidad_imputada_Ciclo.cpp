/*
Sergio Campoy Maldonado, Fundamentos de Programaci�n 1�C
Programa que recibe una lista de matr�culas con su correspondiente velocidad y
el tipo de radar que las capt� y devuelve la m�xima velocidad imputada junto a
su matr�cula.
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main () {
	//	Declaraci�n de constantes
	const string Terminador = "FIN";
	const double Vel_limite = 100;
	const double Error_fijo_menor = 5;
	const double Error_fijo_mayor = 0.05;
	const double Error_movil_menor = 7;
	const double Error_movil_mayor = 0.07;
	
	//	Declaraci�n de variables
	string matricula;
	string matricula_vel_max;
	char radar;
	double vel_captada, vel_imputada, vel_max = 0;
	bool radar_correcto = true, error = false, fin_prematuro = false;
	
	//	Entrada adelantada
	cout << "<matricula> <tipo de radar> <velocidad>" << endl
		  << "Para terminar la entrada introduzca \"FIN\"" << endl;
	cin >> matricula;
	if (matricula != Terminador) {
		cin >> radar >> vel_captada;
		radar = toupper (radar);
		radar_correcto = ((radar == 'F') || (radar == 'M'));
	}
	else
		fin_prematuro = true;
	
	//	C�lculos y entrada
	while ((matricula != Terminador) && radar_correcto && (vel_captada > 0)) {
		//	C�lculo de la velocidad imputada
		if (radar == 'F') {
			if (vel_captada < Vel_limite)
				vel_imputada = vel_captada - Error_fijo_menor;
			else
				vel_imputada = vel_captada * (1 - Error_fijo_mayor);
		}
		else if (radar == 'M') {
			if (vel_captada < Vel_limite)
				vel_imputada = vel_captada - Error_movil_menor;
			else
				vel_imputada = vel_captada * (1 - Error_movil_mayor);
		}
		
		//	Asignaci�n de la velocidad m�xima
		if (vel_imputada > vel_max) {
			vel_max = vel_imputada;
			matricula_vel_max = matricula;
		}
		
		//	Entrada
		cin >> matricula;
		if (matricula != Terminador) {
			cin >> radar >> vel_captada;
			radar = toupper (radar);
			radar_correcto = ((radar == 'F') || (radar == 'M'));
		}
	}
	
	//	Comprobaci�n de errores
	error = fin_prematuro || !radar_correcto || (vel_captada < 0);
	
	//	Salida
	if (error) {
		if (!radar_correcto) {
			cout << endl
				  << "Error. El tipo de radar no es valido"
				  << endl << endl;
		}
		else if (vel_captada < 0) {
			cout << endl
				  << "Error. La velocidad introducida es incorrecta"
				  << endl << endl;
		}
		else if (fin_prematuro) {
			cout << endl
				  << "Error. No se ha introducido ningun dato"
				  << endl << endl;
		}
	}
	else {
			cout << endl
				  << "La velocidad mayor ha sido " << vel_max
				  << " km/h con matricula " << matricula_vel_max
				  << endl << endl;
	}
}

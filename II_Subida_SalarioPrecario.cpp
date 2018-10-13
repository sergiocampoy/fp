/*
Sergio Campoy Maldonado, Fundamentos de Programación 1ºC

Programa que calcula el nuevo salario de una persona en función de su sueldo
actual y su edad
*/

#include <iostream>
using namespace std;

enum class Precariedad
				{alta, media, baja};

int main () {
	//	Declaración de constantes
	const double subida_edad = 0.04;
	const double subida_salario = 0.03;
	
	//	Declaración de variables
	int edad;
	double salario_inicial, salario;
	Precariedad persona;
	
	//	Entrada de datos
	do {
		cout << "Introduce la edad de la persona: ";
		cin >> edad;
	} while (edad < 0);
	
	do {
		cout << "Introduce el salario de la persona: ";
		cin >> salario_inicial;
	} while (salario_inicial < 0);
	
	//	Cálculos
	if ((edad > 65) || (edad < 35)) {
		if (salario_inicial < 300)
			persona = Precariedad::alta;
		else
			persona = Precariedad::media;
	}
	else
		persona = Precariedad::baja;
	
	salario = salario_inicial;
	
	switch (persona) {
		case Precariedad::alta:
			salario = salario + salario * subida_salario;
			
		case Precariedad::media:
			salario = salario + salario * subida_edad;
			break;
		
		case Precariedad::baja:
			salario = salario;
			break;
	}
	
	//	Salida
	cout << endl
		  << "El nuevo salario es " << salario
		  << endl << endl;
}

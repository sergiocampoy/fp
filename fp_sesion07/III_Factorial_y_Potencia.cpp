/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que implementa un menú con 3 opciones:
	1. Calcula el factorial de un número de forma no recursiva haciendo uso de un
		bucle for
	
	2. Calcula el resultado de elevar una base a un exponente, multiplicando la
		base tantas veces como indique el exponente en un bucle for
	
	3. Sale del menú y termina el programa

Esta vez hace uso de funciones
*/

#include <iostream>

#include <string>

#include <cctype>

using namespace std;

enum class Accion
			{Factorial, Potencia, Salir, Error};



int LeeEnteroPositivo (string mensaje) {
	//	Declaración de variables
	int n;
	
	//	Entrada de datos
	do {
		cout << mensaje;
		cin >> n;
	} while (n < 0);
	
	//	Return
	return n;
}



int Calcula_Factorial (int n) {
	if (n > 1)
		return (n * Calcula_Factorial (n-1));
	else
		return 1;
}

double Calcula_Potencia (double a, int b) {
	//	Declaración de variables
	double n = 1;
	
	//	Cálculos
	for (int i = 1; i <= b; i++) {
		n *= a;
	}
	
	//	Return
	return n;
}



int main (void) {
	//	Declaración de variables
	Accion accion;
	string mensaje;
	char respuesta;
	double base;
	int exp, factorial;
	bool salir = false;
	
	do {
		//	Salida del menu
		cout << "Menu principal:" << endl
			  << "\t(F/f) Calcular factorial" << endl
			  << "\t(P/p) Calcular potencia" << endl
			  << "\t(S/s) Salir" << endl;
		
		//	Entrada del menu
		cin >> respuesta;
		respuesta = toupper (respuesta);
		
		//	Asignación de la entrada
		if (respuesta == 'F')
			accion = Accion::Factorial;
		else if (respuesta == 'P')
			accion = Accion::Potencia;
		else if (respuesta == 'S')
			accion = Accion::Salir;
		else
			accion = Accion::Error;
		
		switch (accion) {
			case Accion::Factorial:
				mensaje = "Introduce un numero positivo: ";
				factorial = Calcula_Factorial (LeeEnteroPositivo(mensaje));
				cout << endl
					  << "El factorial es " << factorial
					  << endl << endl;
				break;
				
			case Accion::Potencia:
				//	Entrada
				cout << "Introduce una base: ";
				cin >> base;
				
				exp = LeeEnteroPositivo ("Introduce el exponente: ");
				
				//	Salida
				cout << endl
					  << base << " elevado a " << exp << " = "
					  << Calcula_Potencia (base, exp)
					  << endl << endl;
				break;
			
			case Accion::Salir:
				salir = true;
				break;
			
			case Accion::Error:
				cout << endl
					  << "Error. El caracter introducido no es un caracter valido"
					  << endl << endl;
				break;
		}
	} while (!salir);
}

#include <iostream>
#include <cctype>
using namespace std;

enum class Accion
			{Factorial, Potencia, Salir, Error};

int main () {
	//	Declaración de variables
	int n, exp, factorial;
	double base, potencia;
	char respuesta;
	bool salir = false;
	Accion accion;

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
				//	Entrada
				do {
					cout << "Introduce un numero: ";
					cin >> n;
				} while (n < 0);

				//	Cálculo
				factorial = 1;
				for (int i = 0; i < n; i++)
					factorial *= (n - i);
				
				//	Salida
				cout << endl
					  << n << "! = " << factorial
					  << endl << endl;
				break;
				
			case Accion::Potencia:
				//	Entrada
				cout << "Introduce una base: ";
				cin >> base;
				
				do {
					cout << "Introduce un exponente: ";
					cin >> exp;
				} while (exp < 0);
				
				//	Cálculo
				potencia = 1;
				for (int i = 0; i < exp; i++)
					potencia *= base;
				
				//	Salida
				cout << endl
					  << base << " elevado a " << exp << " = " << potencia
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

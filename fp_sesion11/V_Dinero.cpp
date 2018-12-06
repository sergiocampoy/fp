/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que, haciendo uso de clases, pide el precio inicial de un produco, el
incremento mensual que sufre y el número de meses que lo sufre. Devuelve el
precio mes a mes.
*/

#include <iostream>

#include <string>

#include <iomanip>

using namespace std;

class Dinero {
	
	private:
		//	Datos privados
		int euros,
			 centimos;
		
		//	Métodos privados
		void Corregir () {
			if (centimos >= 100) {
				euros += centimos / 100;
				centimos = centimos % 100;
			}
		}
		
		bool ValoresCorrectos (int valor_euros, int valor_centimos) {
			bool bien = true;
			
			if ((valor_euros < 0) || (valor_centimos < 0))
				bien = false;
			else if (valor_euros + valor_centimos == 0)
				bien = false;
			
			return bien;
		}

	public:
		
		//	Constructores
		Dinero ()
			:	euros (0),
				centimos (0)
			{}
		
		Dinero (int euros_ini, int centimos_ini)
			:	euros (euros_ini),
				centimos (centimos_ini)
			{}
		
		//	Métodos públicos
		void Incrementar (int valor_euros, int valor_centimos) {
			if (valor_euros + valor_centimos > 0) {
				centimos += valor_centimos;
				euros += valor_euros;
				Corregir();
			}
		}
		
		void (Incrementar (Dinero incremento)) {
			centimos += incremento.centimos;
			Corregir();
			euros += incremento.euros;
		} 
		
		double Saldo () {
			return (euros + centimos/100.0);
		}
};

int main () {

	//	Declración de variables
	int euros, centimos;
	
	
	//	Entrada
	cout << "Introduce el precio inicial:" << endl;
	do {
		cout << "Euros: ";
		cin >> euros;
	} while (euros < 0);
	do {
		cout << "Centimos:";
		cin >> centimos;
	} while (centimos < 0);
	
	Dinero saldo (euros, centimos);
	
	cout << "Introduce el incremento mensual:" << endl;
	do {
		cout << "Euros: ";
		cin >> euros;
	} while (euros < 0);
	do {
		cout << "Centimos:";
		cin >> centimos;
	} while (centimos < 0);
	
	Dinero incremento (euros, centimos);
	
	int meses;
	do {
		cout << "Introduce el numero de meses: ";
		cin >> meses;
	} while (meses < 0);
	
	cout << endl;
	
	for (int i = 1; i <= meses; i++) {
		saldo.Incrementar(incremento);
		cout << "En el mes " << i << " el precio del producto es "
			  << fixed << setprecision (2) << saldo.Saldo()
			  << endl;
	}
	
	return 0;
}

/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que implementa los métodos EsMayor, Incrementa, Decrementa, Modifica
y Diferencia en la clase Dinero
*/

#include <iostream>

#include <string>

using namespace std;

class Dinero {
	private:
		//	Datos privados
		int euros, centimos;
		
		//	Métodos privados
		void Corregir () {
			if (centimos >= 100) {
				euros += centimos / 100;
				centimos = centimos % 100;
			}
		}
		
		//	Convierte de euros'centimos a la clase Dinero
		//	PRE:	cantidad > 0
		Dinero DoubleADinero (double cantidad) {
			int c = cantidad * 100;			//	Obtiene los centimos totales
			
			if (100 * cantidad - c >= 0.5)//	[0.1~0.9] 
				c++;								//	Aproxima a las centenas
			
			//	Llama al constructor con argumentos
			Dinero final (0, c);				//	Convierte de centimos a clase Dinero
			return final;						//	Devuelve dinero
		}
		
	public:
		//	Constructor sin argumentos
		Dinero (): euros (0), centimos (0) {}
		
		//	Constructor con argumentos
		//	PRE:	e >= 0
		//			c >= 0
		Dinero (int e, int c): euros (e), centimos (c) {
			Corregir ();
		}
		
		string ToString () {
			string cad = to_string (euros) + ',';
			
			if (centimos < 10)
				cad += '0';
			
			cad += to_string (centimos) + " euros";
			return cad;
		}
		
		//	Métodos GET
		double GetTotalEuros () {
			return (euros + centimos / 100.0);
		}
		
		int GetTotalCentimos () {
			return (100*euros + centimos);
		}
		
		int GetEuros () {
			return euros;
		}
		
		int GetCentimos () {
			return centimos;
		}
		
		//	Métodos
		
		//	PRE:	e > 0
		void SetEuros (int e) {
			euros = e;
		}
		
		//	PRE:	c > 0
		void SetCentimos (int c) {
			centimos = c;
			Corregir ();
		}
		
		//	Ejercicio 5
		
		
		bool EsMayor (Dinero otro) {
			return (GetTotalEuros() > otro.GetTotalEuros());
		}
		
		bool EsMayor (int e, int c) {
			Dinero otro (e, c);
			//	Llama al método "bool EsMayor (Dinero otro)"
			return EsMayor (otro);
		}
		
		bool EsMayor (double cantidad) {
			Dinero otro = DoubleADinero (cantidad);
			//	Llama al método "bool EsMayor (Dinero otro)"
			return (EsMayor (otro));
		}
		
		Dinero Incrementa (Dinero cantidad) {
			int delta = cantidad.GetTotalCentimos();
			Dinero final (euros, centimos + delta);
			return final;
		}
		
		//	PRE:	EsMayor (cantidad) = true
		Dinero Decrementa (Dinero cantidad) {
			int c = GetTotalCentimos() - cantidad.GetTotalCentimos();
			
			return Dinero (0, c);
		}
		
		Dinero Modifica (double cantidad) {
			Dinero final;
			if (cantidad < 0)
				final = Decrementa (DoubleADinero (-cantidad));
			else
				final = Incrementa (DoubleADinero (cantidad));
			
			return final;
		}
		
		Dinero Diferencia (Dinero otro) {
			int delta = GetTotalCentimos () - otro.GetTotalCentimos();
			Dinero final;	//	Constructor sin argumentos (e = 0, c = 0)
			
			if (delta < 0)
				delta = -delta;
				
			final.SetCentimos(delta);
			return final;
		}
};

int main () {
	
	int euros, centimos;
	
	cout << "Introduce una cantidad de dinero:" << endl;

	do {
		cout << "\tEuros: ";
		cin >> euros;
	} while (euros < 0);
	
	do {
		cout << "\tCentimos: ";
		cin >> centimos;
	} while (centimos < 0);
	
	Dinero a (euros, centimos);
	
	cout << "Introduce otra cantidad de dinero:" << endl;

	do {
		cout << "\tEuros: ";
		cin >> euros;
	} while (euros < 0);
	
	do {
		cout << "\tCentimos: ";
		cin >> centimos;
	} while (centimos < 0);
	
	Dinero b (euros, centimos);
	
	if (a.EsMayor(b))
		cout << a.ToString() << " es mayor que " << b.ToString() << endl;
	else
		cout << b.ToString() << " es mayor que " << a.ToString() << endl;
		
	if (a.EsMayor(b.GetEuros(), b.GetCentimos()))
		cout << a.ToString() << " es mayor que " << b.ToString() << endl;
	else
		cout << b.ToString() << " es mayor que " << a.ToString() << endl;
	
	if (a.EsMayor(b.GetTotalEuros()))
		cout << a.ToString() << " es mayor que " << b.ToString() << endl;
	else
		cout << b.ToString() << " es mayor que " << a.ToString() << endl;
	
	cout << "La suma de " << a.ToString() << " y " << b.ToString()
		  << " es " << a.Incrementa(b).ToString()
		  << endl;
	
	if (a.EsMayor(b))
		cout << a.ToString() << " decrementado " << b.ToString()
			  << " es " << a.Decrementa(b).ToString()
			  << endl;
	else
		cout << b.ToString() << " decrementado " << a.ToString()
			  << " es " << b.Decrementa(a).ToString()
			  << endl;
	
	double dinero;
	do {
		cout << "Indique una cantidad de dinero (euros.centimos): ";
		cin >> dinero;
	} while (dinero < -a.GetTotalEuros());
	
	cout << "Al modificar " << a.ToString() << " " << dinero
		  << " euros, el resultado es " << a.Modifica(dinero).ToString() << endl;
		  
	cout << "La diferencia entre " << a.ToString() << " y " << b.ToString()
		  << " es de " << a.Diferencia(b).ToString() << endl;
	
	return 0;
}

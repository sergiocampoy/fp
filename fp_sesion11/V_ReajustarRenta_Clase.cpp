/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que implementa la clase LectorOpcion2Alternativas para ajustar la renta
de una persona en función de su sueldo bruto, si es autonomo, pensionista o esta
casado.
*/

#include <iostream>

#include <string>

#include <cctype>

using namespace std;

class LectorOpcion2Alternativas {
	private:
		bool
			autonomo,
			pensionista,
			casado;
		
		double
			renta,
			retencion_inicial,
			delta_retencion;
			
		bool LeeOpcion2Alternativas (string mensaje) {
			char respuesta;
			
			cout << mensaje << " (S/N)" << endl;
			cin >> respuesta;
			
			switch (toupper (respuesta)) {
				case 'S':
					return true;
					break;
				
				case 'N':
					return false;
					break;
				
				default:
					return LeeOpcion2Alternativas (mensaje);
			}
		}
		
		void EsAutonomo () {
			autonomo = LeeOpcion2Alternativas ("Es autonomo?");
		}
		
		void EsPensionista () {
			pensionista = LeeOpcion2Alternativas ("Es pensionista?");
		}
		
		void EstaCasado () {
			casado = LeeOpcion2Alternativas ("Esta casado?");
		}
		
		void AjustarRetencion () {
			if (autonomo)
				delta_retencion -= 3;
			else
				if (pensionista)
					delta_retencion += 1;
				else {
					delta_retencion += 2;
					if (renta < 20000)
						delta_retencion += 2;
					else
						if (casado)
							delta_retencion += 2.5;
						else
							delta_retencion += 3;
				}
		}
		
		void SetRenta (double sueldo) {
			if (sueldo > 0)
				renta = sueldo;
			else
				do {
					cout << "La renta ha de ser positiva." << endl
						  << "Introducela de nuevo: ";
					cin >> renta;
				} while (renta < 0);
		}
		
		void SetRetenciones (double retencion) {
			if ((retencion < 0) || (retencion > 100))
				do {
					cout << "Las retenciones deben pertenecer al intervalo [0-100]."
						  << endl << "Introducelas de nuevo: ";
					cin >> retencion_inicial;
				} while ((retencion_inicial < 0) || (retencion_inicial > 100));
			else
				retencion_inicial = retencion;
		}

	public:
		
		
		//	Constructor
		LectorOpcion2Alternativas (double renta_bruta, double retencion) {
			SetRenta (renta_bruta);
			SetRetenciones (retencion);
			EsAutonomo ();
			EsPensionista ();
			EstaCasado ();
			AjustarRetencion ();
		}
		
		double GetRentaNeta () {
			double retencion_total = retencion_inicial + delta_retencion;
			return (renta - renta * retencion_total / 100);
		}
};




int main () {
	
	//	Declaración de variables
	double renta, retencion;
	
	//	Entrada
	cout << "Introduce la renta: ";
	cin >> renta;
	
	cout << "Introduce las retenciones iniciales: ";
	cin >> retencion;
	
	LectorOpcion2Alternativas persona (renta, retencion);
	
	//	Salida
	cout << "La renta final es " << persona.GetRentaNeta();
		
	return 0;
}

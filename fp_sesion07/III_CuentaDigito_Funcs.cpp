/*
Sergio Campoy Maldonado
Fundamentos de Programaci�n
1�C

Programa que cuenta cu�ntas veces aparece una cifra en un intervalo dado por el
usuario
*/

#include <iostream>

#include <string>

using namespace std;

int CuentaDigitos (int n, char cifra) {
	//	Declaraci�n de variables
	string cad_n, cad_cifra;
	int num_cifras;
	int digitos_que_aparecen = 0;
	
	//	C�lculos
	cad_n = to_string (n);
	num_cifras = cad_n.length ();
	
	for (int i = 0; i < num_cifras; i++)
		if (cad_n.at (i) == cifra)
			digitos_que_aparecen++;
	
	//	Return
	return digitos_que_aparecen;
}

int main (void) {
	//	Declaraci�n de variables
	int min, max, contador = 0;
	char cifra;
	
	//	Entrada de datos
	do {
		cout << "Introduce una cifra (1-9): ";
		cin >> cifra;
	} while ((cifra < '1') || (cifra > '9'));
	
	do {
		cout << "Introduce la cota inferior: ";
		cin >> min;
	} while (min < 0);
	
	do {
		cout << "Introduce la cota superior: ";
		cin >> max;
	} while (max < min);
	
	//	C�lculos
	for (int i = min; i <= max; i++)
		contador += CuentaDigitos (i, cifra);
	
	//	Salida
	cout << endl
		  << "Entre " << min << " y " << max << ", la cifra " << cifra
		  << " aparece " << contador << " veces" << endl;
	
	return 0;
}

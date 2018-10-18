/*
Sergio Campoy Maldonado, Fundamentos de Programaci�n 1�C

Programa que cuenta cu�ntas veces aparece una cifra en un intervalo dado por el
usuario
*/

#include <iostream>

using namespace std;

int main () {
	//	Declaraci�n de variables
	int j, resto, cifra, contador = 0, min, max;
	
	//	Entrada
	do {
		cout << "Introduce una cifra (1-9): ";
		cin >> cifra;
	} while ((cifra < 1) || (cifra > 9));
	
	do {
		cout << "Introduce la cota inferior: ";
		cin >> min;
	} while (min < 0);
	
	do {
		cout << "Introduce la cota superior: ";
		cin >> max;
	} while (max < min);
	//	C�lculos
	for (int i = min; i <= max; i++) {
		j = i;
		do {
			resto = j % 10;
			if (resto == cifra)
				contador++;
			j = j/10;
		} while (j != 0);
	}
	
	//	Salida
	cout << endl
		  << "Entre " << min << " y " << max << ", la cifra " << cifra
		  << " aparece " << contador << " veces" << endl;
}

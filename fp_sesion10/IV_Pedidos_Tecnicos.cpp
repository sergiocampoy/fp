/*
Sergio Campoy Maldonado
Fundamentos de Programaci�n
1�C

Programa que asigna un trabajo a cada t�cnico de la forma m�s econ�mica
*/

#include <iostream>

using namespace std;

int main (void) {
	
	//	Declaraci�n de constantes
	const int SIZE = 100;
	const int OCUPADO = -1;
	
	
	//	Declaraci�n de matrices
	bool a [SIZE] [SIZE] = {false};
	double t [SIZE] [SIZE];
	
	
	//	Declaraci�n de variables
	int usado;
	
	
	//	Entrada
	do {
		cout << "Cuantos pedidos hay? ";
		cin >> usado;
	} while (usado < 1);
	
	for (int i = 0; i < usado; i++)
		for (int j = 0; j < usado; j++)
			do {
				cin >> t [i] [j];
			} while (t [i] [j] <= 0);


	//	Asignaci�n	
	for (int i = 0; i < usado; i++) {
		
		//	Declaraci�n del primer posible minimo
		int pos_minimo = 0;
		while (t [i] [pos_minimo] == OCUPADO)
			pos_minimo++;
		
		//	Encuentra el m�nimo de la fila
		for (int j = pos_minimo; j < usado; j++) {

			if (t [i] [j] != OCUPADO)
				if (t [i] [j] < t [i] [pos_minimo])
					pos_minimo = j;
		}
		
		a [i] [pos_minimo] = true;
		
		//	Evita que el t�cnico acepte m�s trabajos
		for (int k = i + 1; k < usado; k++)
			t [k] [pos_minimo] = OCUPADO;
	}
	
	
	//	C�lculo del precio final
	double suma = 0;
	
	for (int i = 0; i < usado; i++)
		for (int j = 0; j < usado; j++)
			if (a [i] [j] == true)
				suma += t [i] [j];
	
	
	//	Salida
	cout << endl
		  << "El precio total es " << suma
		  << endl << endl;
	
	return 0;
}

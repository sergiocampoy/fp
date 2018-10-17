/*
Sergio Campoy Maldonado, Fundamentos de Programaci�n 1�C

Programa que simula un juego de adivinar un n�mero. El usuario introduce n�meros
hasta que este coincida con el n�mero generado pseudoaleatoriamente por el
programa. El usuario puede abandonar en mitad del juego o jugar de nuevo al
terminar una partida
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>
using namespace std;

int main () {
	//	Declaraci�n de constantes
	const int MIN = 1;
	const int MAX = 100;
	const int NUM_VALORES = MAX-MIN + 1;	// N�mero de valores posibles
	const int Terminador = -1;
	
	//	Declaraci�n de variables
	int incognita; // n�mero aleatoria a generar
	int intento;
	char respuesta;
	bool juego = true;
	bool otra_partida = false;

	//	Inicializa el generador de n�ms. aleatorios con el reloj del sistema
	time_t t;
	srand(time(&t));

	// Generaci�n de incognita (MIN <= incognita <= MAX)
	incognita = (rand() % NUM_VALORES) + MIN;
	
	do {
		cout << "Introduce un numero (o -1 para terminar): ";
		while (juego == true) {
			cin >> intento;
			
			if (intento == Terminador) {
				juego = false;
			}
			else {
				if (intento < incognita)
					cout << intento << " esta por debajo\tIntroduce otro: ";
				else if (intento > incognita)
					cout << intento << " esta por encima\tIntroduce otro: ";
				else {
					cout << endl
						  << "Enhorabuena! Has acertado!"
						  << endl << endl;
					juego = false;
				}
			}
		}
		cout << "Quieres juegar de nuevo? (S/N): ";
		cin >> respuesta;
		respuesta = toupper (respuesta);
		
		if (respuesta == 'S') {
			otra_partida = true;
			juego = true;
			incognita = (rand() % NUM_VALORES) + MIN;
		}
		else
			otra_partida = false;
	} while (otra_partida);
}

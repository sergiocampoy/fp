/*
Sergio Campoy Maldonado
Fundamentos de Programaci�n
1�C

Programa que recibe el n�mero de esca�os a distribuir, el n�mero de partidos que
participan y los votos de cada partido y devuelve el n�mero de esca�os que le
corresponde a cada partido usando el sistema D'Hondt
*/

#include <iostream>

using namespace std;

int main (void) {
	
	//	Declaraci�n de constantes
	const int SIZE = 10;
	const char DELTA = 'A';


	//	Declaraci�n de variables
	int total_escanyos, partidos;
	int votos [SIZE];
	int escanyos [SIZE] = {0};
	int partido_mas_votado;
	int mas_votos, mas_votos_candidato;


	//	Entrada
	do {
		cout << "Introduce el numero de escanyos: ";
		cin >> total_escanyos;
	} while (total_escanyos < 0);
	
	do {
		cout << "Introduce el numero de partidos: ";
		cin >> partidos;
	} while (partidos < 0);
	
	for (int i = 0; i < partidos; i++) {
		do {
			cout << "Introduce el n�mero de votos del partido "
				  << (char) (i + DELTA) << " ";
			cin >> votos [i];
		} while (votos [i] < 0);
	}


	//	C�lculos
	for (int i = 0; i < total_escanyos; i++) {
		partido_mas_votado = 0;
		mas_votos = votos [0] / (escanyos [0] + 1);
		
		for (int j = 1; j < partidos; j++) {
			mas_votos_candidato = votos [j] / (escanyos [j] + 1);
			
			if (mas_votos_candidato > mas_votos) {
				partido_mas_votado = j;
				mas_votos = mas_votos_candidato;
			}
		}
		
		escanyos [partido_mas_votado] ++;
	}
	

	//	Salida
	for (int i = 0; i < partidos; i++) {
		cout << "El partido " << (char) (i + DELTA) << " ha obtenido "
			  << escanyos [i] << " escanyos" << endl;
	}
	
	return 0;
}

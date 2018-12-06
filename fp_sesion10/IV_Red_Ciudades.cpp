/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC


*/

#include <iostream>

#include <iomanip>

#include <cmath>

using namespace std;

int main (void) {
	
	//	Declaración de constantes
	const int MAX_CIUDADES = 50;
	const int TERMINADOR = -1;
	
	//	Declaración de matriz
	double distancia [MAX_CIUDADES] [MAX_CIUDADES] = {0};
	
	//	Entrada
	int ciudades;
	do {
		cout << "Introduce el numero de ciudades: ";
		cin >> ciudades;
	} while ((ciudades <= 0) || (ciudades > MAX_CIUDADES));
	
	int contador_aux = 1;
	for (int i = 0; i < ciudades - 1; i++) {
		
		for (int j = contador_aux; j < ciudades; j++){
			do {
				cout << "Introduce la distancia entre C" << i + 1 << " y C"
																	  << j + 1 << ": ";
				cin >> distancia [i] [j];
			} while (distancia [i] [j] < 0);
			
			distancia [j] [i] = distancia [i] [j];
		}
		contador_aux++;
	}
	
	//	Salida de la matriz de distancias
	cout << endl;
	
	for (int i = 0; i < ciudades; i++) {
		for (int j = 0; j < ciudades; j++)
			cout << setw (3) << distancia [i] [j] << " ";
		cout << endl;
	}


	//	Cálculo de la ciudad más conectada
	int max_conexiones = 0;
	int ciudad_mas_conectada;
	
	for (int i = 0; i < ciudades; i++) {
		int pos_max_conexiones = 0;
		for (int j = 0; j < ciudades; j++) {
			if (distancia [i] [j] != 0)
				pos_max_conexiones++;
		}
		if(pos_max_conexiones > max_conexiones) {
			ciudad_mas_conectada = i;
			max_conexiones = pos_max_conexiones;
		}
	}
	
	cout << endl
		  << "La ciudad más conectada es C" << ciudad_mas_conectada + 1
		  << " con " << max_conexiones << " conexiones" << endl;
	
	
	//	Cálculo del número de conexiones
		//	Entrada
	int ciudad_a;
	do {
		cout << "Introduce una ciudad para averiguar con cuales esta conectada: ";
		cin >> ciudad_a;
	} while ((ciudad_a <= 0) || (ciudad_a > ciudades));
	
		//	Cálculo
	int n_conexiones = 0;
	for (int i = 0; i < ciudades; i++)
		if (distancia [ciudad_a - 1] [i] != 0)
			n_conexiones++;
		
		//	Salida
	cout << "La ciudad C" << ciudad_a << " tiene " << n_conexiones
		  << " conexiones" << endl;
		  
	
	//	Cálculo de la distancia entre dos ciudades no conectadas
		//	Entrada	  
	int ciudad_b;
	do {
		cout << "Introduce dos ciudades entre las que no haya conexion directa: ";
		cin >> ciudad_a >> ciudad_b;
	} while (distancia [ciudad_a] [ciudad_b] != 0);
	
	ciudad_a--;
	ciudad_b--;
	
		//	Cálculo
	int ciudad_dist_min = -1;
	double dist_min = 10e300;
	for (int i = 0; i < ciudades; i++) {
		
		if ((distancia [ciudad_a] [i] != 0) && (distancia [ciudad_b] [i] != 0)) {
			
			double dist_a_b = distancia [ciudad_a] [i] + distancia [ciudad_b] [i];
			if (dist_a_b < dist_min) {
				ciudad_dist_min = i;
				dist_min = dist_a_b;
			}
		}
	}
	
		//	Salida
	if (ciudad_dist_min == -1) {
		cout << "C" << ciudad_a + 1 << " y C" << ciudad_b + 1
			  << " no estan conectadas" << endl;
	}
	else {
		cout << "C" << ciudad_a + 1 << " y C" << ciudad_b + 1
			  << " estan a " << dist_min << "km pasando por C" << ciudad_dist_min+1
			  << endl;
	}
	
	//	Comprobación de si varias ciudades introducidas son contiguas
		//	Declaraciones
	int serie [MAX_CIUDADES];
	int entrada, contador = 0;
	
		//	Entrada
	cout << "Introduce varias ciudades para comprobar si estan conectadas"
		  << " directamente (-1 para terminar)" << endl;
	cin >> entrada;
	
	while (entrada != TERMINADOR) {
		serie [contador] = entrada - 1;
		contador++;
		cin >> entrada;
	}
	
		//	Cálculo
	bool salir = false;
	for (int i = 0; (i < contador) && !salir; i++) {
		for (int j = 0; (j < contador) && !salir; j++) {
			salir = ((distancia [serie [i]] [serie [j]] == 0) && (i != j));
		}
	}
		//	Salida
	if (salir)
		cout << "No todas las ciudades introducidas estan conectadas" << endl;
	else
		cout << "Todas las ciudades introducidas estan conectadas" << endl;
	
	return 0;
}

/*
Sergio Campoy Maldonado, Fundamentos de Programación 1ºC

Programa que recibe una serie de datos (sucursal, producto y nº de unidades
vendidas) y devuelve la sucursal que más productos ha vendido.
*/

#include <iostream>

#include <cctype>

using namespace std;

int main () {
	int sucursal, ventas, ventas_1 = 0, ventas_2 = 0, ventas_3 = 0;
	char producto;
	bool salir = false;
	bool sucur_1_mayor, sucur_2_mayor, sucur_3_mayor;
	
	//	Lectura anticipada
	cin >> sucursal;
	if (sucursal != -1)
		cin >> producto >> ventas;
	else
		salir = true;
	
	while (!salir) {
		if (producto != 0)
		switch (sucursal) {
			case 1:
				ventas_1 += ventas;
				break;

			case 2:
				ventas_2 += ventas;
				break;
			
			case 3:
				ventas_3 += ventas;
				break;
		}
		
		cin >> sucursal;
		if (sucursal != -1) {
			cin >> producto >> ventas;
			producto = tolower (producto);
		}
		else
			salir = true;
	}
	
	sucur_1_mayor = (ventas_1 >= ventas_2) && (ventas_1 >= ventas_3);
	sucur_2_mayor = (ventas_2 >= ventas_1) && (ventas_2 >= ventas_3);
	sucur_3_mayor = (ventas_3 >= ventas_1) && (ventas_3 >= ventas_2);
	
	if (sucur_1_mayor) {
		cout << "La sucursal con mas ventas ha sido la sucursal numero 1"
			  << " con un total de " << ventas_1 << " unidades vendidas";
	}
	else if (sucur_2_mayor) {
		cout << "La sucursal con mas ventas ha sido la sucursal numero 2"
			  << " con un total de " << ventas_2 << " unidades vendidas";
	}
	else if (sucur_3_mayor) {
		cout << "La sucursal con mas ventas ha sido la sucursal numero 3"
			  << " con un total de " << ventas_3 << " unidades vendidas";
	}
}

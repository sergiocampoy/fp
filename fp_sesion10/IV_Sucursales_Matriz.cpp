/*
Sergio Campoy Maldonado
Fundamentos de Programaci�n
1�C

Programa que recibe una serie de datos de ventas de productos en sucursales y:
	1)	Calcula el total de unidades vendidas de cada producto
	2) Calcula el producto m�s vendido
	3)	Calcula cu�ntos tipos de productos se han vendido
	4)	El n�mero total de unidades vendidas entre todas las sucursales
*/

#include <iostream>

using namespace std;

int main (void) {
	
	//	Declaraci�n de constantes
	const int TERMINADOR = -1;
	
	// Num. m�ximo de sucursales
	const int MAX_SUCURSALES_EMPRESA = 100;
	const char MAX_PRODUCTO = 'j'; // Cod. m�ximo de producto
	const char MIN_PRODUCTO = 'a';
	const int NUM_PRODUCTOS = MAX_PRODUCTO - MIN_PRODUCTO + 1; // Num. productos
	
	
	//	Declaraci�n de matrices
	int ventas [MAX_SUCURSALES_EMPRESA] [NUM_PRODUCTOS] = {0};
	
	
	//	Declraci�n de los vectores ventas por producto y por sucursal
	int ventas_sucursal [MAX_SUCURSALES_EMPRESA] = {0};
	int ventas_producto [NUM_PRODUCTOS] = {0};
	
	
	//	Declaraci�n de variables
	int sucursal, unidades;
	char producto;
	
	
	//	Entrada adelantada
	do {
		cout << "Sucursal [0-100] (-1 para terminar): ";
		cin >> sucursal;
	} while (((sucursal != TERMINADOR) && (sucursal <= 0))
						|| (sucursal > MAX_SUCURSALES_EMPRESA));
	
	while (sucursal != TERMINADOR) {
		
		do {
			cout << "Producto [a-j]: ";
			cin >> producto;
		} while ((producto < MIN_PRODUCTO) || (producto > MAX_PRODUCTO));
		
		do {
			cout << "Unidades: ";
			cin >> unidades;
		} while (unidades <= 0);
		
		ventas [sucursal] [producto - MIN_PRODUCTO] += unidades;
		ventas_sucursal [sucursal] += unidades;
		ventas_producto [producto - MIN_PRODUCTO] += unidades;
		
		do {
			cout << "Sucursal: ";
			cin >> sucursal;
		} while (((sucursal != TERMINADOR) && (sucursal <= 0))
							|| (sucursal > MAX_SUCURSALES_EMPRESA));
	}
	
	
	cout << endl
		  << "El total de ventas por producto ha sido:"
		  << endl;

	int prod_mas_ventas = 0;
	int n_productos_vendidos = 0;
	int ventas_totales = 0;
	
	for (int i = 0; i < NUM_PRODUCTOS; i++)
		if (ventas_producto [i] != 0) {

			//	Salida del numero de ventas / producto
			cout << "\tProducto " << (char) (i + MIN_PRODUCTO) << " = "
				  << ventas_producto [i] << endl;

			//	C�lculo del producto m�s vendido
			if (ventas_producto [i] > ventas_producto [prod_mas_ventas])
				prod_mas_ventas = i;
			
			//	C�lculo del n�mero de ventas totales
			ventas_totales += ventas_producto [i];
			
			//	C�lculo del n�mero de productos distintos vendidos
			n_productos_vendidos ++;
		}
	
	
	//	Salida
	cout << endl
		  << "El producto \"" << (char) (prod_mas_ventas + MIN_PRODUCTO)
		  << "\" ha sido el producto con mas ventas con "
		  << ventas_producto [prod_mas_ventas] << " ventas en total"
		  << endl;
	
	cout << "Se han vendido " << n_productos_vendidos << " productos distintos"
		  << endl;
	
	cout << "En total se han producido " << ventas_totales
		  << " ventas entre todas las sucursales"
		  << endl;
	
	return 0;
}

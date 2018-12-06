/*
Sergio Campoy Maldonado
Fundamentos de Programación
1ºC

Programa que implementa 4 algoritmos de ordenación en SecuenciaEnteros
*/

#include <iostream>

using namespace std;

/***************************************************************************/
// Clase: Cronometro
/*
	Sirve para medir el tiempo de ejecución de un conjunto de instrucciones.
	
	Hay crear un objeto de esta clase y justo antes del conjunto de 
	instrucciones que queramos cronometrar, debemos ejecutar el 
	método "Reset". Justo después de las instrucciones que queremos 
	cronometrar llamaremos al método "NanoSegundosTranscurridos" 
	(resp. "MiliSegundosTranscurridos") para saber el número de nanosegundos 
	(resp. milisegundos) transcurridos. 
	
	El cronómetro seguirá en marcha (por lo que podremos llamar al método 
	"NanoSegundosTranscurridos"  tantas veces como queramos) hasta reiniciar 
	el cronómetro (método "Reset").
*/
/***************************************************************************/

#include <chrono>

/////////////////////////////////////////////////////////////////////////////

class Cronometro
{
	
private:
	
   typedef std::chrono::time_point<std::chrono::steady_clock>
           Punto_en_el_Tiempo;
   typedef chrono::duration <double, nano> IntervaloTiempo;

   Punto_en_el_Tiempo inicio;
   Punto_en_el_Tiempo final;

public:
	
	/***********************************************************************/
   void Reset(){
      inicio = chrono::steady_clock::now();
   }
   
   /************************************************************************/
   double NanoSegundosTranscurridos(){
      final = chrono::steady_clock::now();
      IntervaloTiempo diferencia = final - inicio;
      return diferencia.count();
   }
   
   /************************************************************************/
   double MiliSegundosTranscurridos(){
      return (NanoSegundosTranscurridos()/1e6);
   }
    /************************************************************************/  
};

/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
// Clase: GeneradorAleatorioEnteros
/*
	Sirve para generar números aleatorios enteros en un rango de valores.
	
	Hay crear un objeto de esta clase. Se dispone de dos constructores: 
	1) GeneradorAleatorioEnteros()
	   		El primero no tiene parámetros y establece que únicamente se 
			van a generar ceros y unos (este constructor llama al segundo). 
	2) GeneradorAleatorioEnteros(int min, int max)
		El segundo tiene dos parámetros, "min" y "max" que delimitan el 
		rango correspondiente. 

	Finalmente, el método 
	
		int Siguiente()
	
	devolverá un valor aleatorio en el rango especificado en el constructor.
*/
/***************************************************************************/
#include <random>  // para la generación de números pseudoaleatorios
#include <chrono>  // para la semilla

using namespace std;

/////////////////////////////////////////////////////////////////////////////
class GeneradorAleatorioEnteros
{  
private:
	
	mt19937 generador_mersenne;    // Mersenne twister
	uniform_int_distribution<int>  distribucion_uniforme;
	
	/************************************************************************/
	
	long long Nanosec(){
		return (chrono::high_resolution_clock::now().time_since_epoch().count());
	}
	
	/************************************************************************/ 
	
public:
	
	/************************************************************************/
		
	GeneradorAleatorioEnteros() : GeneradorAleatorioEnteros(0, 1) 
	{ }
	
	/************************************************************************/  
	GeneradorAleatorioEnteros(int min, int max) {
	
		const int A_DESCARTAR = 70000;
		// ACM TOMS Volume 32 Issue 1, March 2006
		
		auto semilla = Nanosec();
		generador_mersenne.seed(semilla);
		generador_mersenne.discard(A_DESCARTAR);
		distribucion_uniforme = uniform_int_distribution<int> (min, max);
	}
	
	/************************************************************************/
	
	int Siguiente(){
	  return (distribucion_uniforme(generador_mersenne));
	}
	
	/************************************************************************/

};
/////////////////////////////////////////////////////////////////////////////



class SecuenciaEnteros {

	private:
		//	Datos privados
		static const int SIZE = 10000;
		int secuencia [SIZE];
		int usados;

	public:
		//	Constructor sin argumentos
		SecuenciaEnteros ():
			usados (0)
		{}
		
		//	Métodos públicos
		int GetUsados () {
			return usados;
		}
		
		int GetSize () {
			return SIZE;
		}
		
		void Reset () {
			usados = 0;
		}
		
		//	PRE: usados < SIZE
		void Add (int n) {
			if (usados < SIZE) {
				secuencia [usados] = n;
				usados++;
			}
		}
		
		//	PRE: 0 <= n < usados
		int Elemento (int n) {
			return secuencia [n];
		}
		
		//	PRE: 0 <= pos < usados
		void Cambia (int pos, int n) {
			if (pos < usados) {
				secuencia [pos] = n;
			}
		}
		
		//	PRE: 0 <= pos < usados
		void Elimina (int pos) {
			if ((0 <= pos) && (pos < usados)) {
				for (int i = pos; i < usados - 1; i++)
					secuencia [i] = secuencia [i + 1];
				usados--;
			}
		}
		
		//	PRE: usados < SIZE
		//		  0 <= pos < usados
		void Inserta (int n, int pos) {
			if ((0 <= pos) && (pos < usados) && (usados < SIZE)) {
				for (int i = usados; i > pos; i--) {
					secuencia [i] = secuencia [i - 1];
				}
				secuencia [pos] = n;
			}
			usados++;
		}
		
		string ToString () {
			string cad;
			
			cad = "{" + to_string (secuencia [0]);
			for (int i = 1; i < usados; i++)
				cad += ", " + to_string (secuencia [i]);
			cad += "}";
			
			return cad;
		}
		
		int GetNumSecuenciasAscendentes () {
			int rachas = 1;

			for (int i = 1; i < usados; i++)
				if (secuencia [i] < secuencia [i - 1])
					rachas++;
			
			
			return rachas;
		}
		
		//	PRE:	0 <= a < usados
		//			0 <= b < usados
		void Intercambia (int a, int b) {
			if ((0 <= a) && (0 <= b) && (a < usados) && (b < usados)) {
				int aux = secuencia [a];
				secuencia [a] = secuencia [b];
				secuencia [b] = aux;
			}
		}
		
		//	PRE:	0 <= a < usados
		//			0 <= b < usados
		void Mueve (int pos_a, int pos_b) {
			if ((0 <= pos_a) && (0 <= pos_b)
			&& (pos_a < usados) && (pos_b < usados)) {
				Inserta (secuencia [pos_a], pos_b);
				Elimina (pos_a + 1);
			}
		}
		
		void OrdenaSeleccion () {
			int min;
			
			for (int izda = 0; izda < usados; izda++) {
				//	Calcula el mínimo
				min = izda;
				for (int i = izda; i < usados; i++) {
					if (secuencia [i] < secuencia [min])
						min = i;
				}
				//	Coloca el mínimo al principio
				Mueve (min, izda);
			}
		}
		
		void OrdenaInsercion () {
			int i;
			for (int izda = 1; izda < usados; izda++) {
				i = 0;
				while ((i < izda) && (secuencia [izda] > secuencia [i]))
					i++;
				Mueve (izda, i);
			}
		}
		
		void OrdenaIntercambio () {
			for (int izda = 0; izda < usados; izda ++)
				for (int i = usados - 1; i > izda; i--)
					if (secuencia [i] < secuencia [i - 1])
						Intercambia (i, i - 1);
		}
		
		void OrdenaIntercambioMejorado () {
			bool ordenados = false;
			for (int izda = 0; (izda < usados) && !ordenados; izda ++) {
				ordenados = true;
				for (int i = usados - 1; i > izda; i--)
					if (secuencia [i] < secuencia [i - 1]) {
						Intercambia (i, i - 1);
						ordenados = false;
					}
			}
		}
};

int main () {

	//	Constructores sin argumentos
	Cronometro tiempo;
	SecuenciaEnteros original;
	
	//	Declaración de variables
	double
		tiempo1,
		tiempo2,
		tiempo3,
		tiempo4;

	//	Entrada
	int total, n;
	cout << "Cuantos numeros se van a introducir (< 10 000)? ";
	cin >> total;
	
	for (int i = 0; i < total; i++) {
		cin >> n;
		original.Add(n);
	}
	
	//	Muestra cadena original
	cout << "La cadena original es:" << endl
		  << original.ToString()
		  << endl << endl;


	//	Ordena mediante selección
	SecuenciaEnteros copia1 = original;
	
	tiempo.Reset();
	copia1.OrdenaSeleccion();
	tiempo1 = tiempo.NanoSegundosTranscurridos();
	
	cout << "La cadena ordenada mediante seleccion es:" << endl
		  << copia1.ToString()
		  << endl;
	

	//	Ordena mediante inserción
	SecuenciaEnteros copia2 = original;

	tiempo.Reset();
	copia2.OrdenaInsercion();
	tiempo2 = tiempo.NanoSegundosTranscurridos();
	
	cout << "La cadena ordenada mediante insercion es:" << endl
		  << copia2.ToString()
		  << endl;
	
	
	//	Ordena mediante intercambio directo
	SecuenciaEnteros copia3 = original;

	tiempo.Reset();
	copia3.OrdenaIntercambio ();
	tiempo3 = tiempo.NanoSegundosTranscurridos();
	
	cout << "La cadena ordenada mediante intercambio directo es:" << endl
		  << copia3.ToString()
		  << endl;
		
	
	//	Ordena mediante intercambio directo mejorado
	SecuenciaEnteros copia4 = original;

	tiempo.Reset();
	copia4.OrdenaIntercambioMejorado ();
	tiempo4 = tiempo.NanoSegundosTranscurridos();
	
	cout << "La cadena ordenada mediante intercambio directo mejorado es:"
		  << endl << copia4.ToString() << endl;


	//	Muestra los tiempos de ejecución de los algoritmos de ordenación
	cout << "Los tiempos de ejecucion han sido:" << endl
		  << "\tSeleccion:            " << tiempo1 << endl
		  << "\tInsercion:            " << tiempo2 << endl
		  << "\tIntercambio:          " << tiempo3 << endl
		  << "\tIntercambio mejorado: " << tiempo4 << endl;


	//	Ordena una cadena generada aleatoriamente
	cout << endl
		  << "Ahora se va a ordenar una cadena aleatoria de 10000 numeros"
		  << endl;

	GeneradorAleatorioEnteros test (0, 10000);
	
	for (int i = 0; i < 10000; i++) {
		n = test.Siguiente();
		original.Add(n);
	}


	copia1 = original;
	tiempo.Reset();
	copia1.OrdenaSeleccion();
	tiempo1 = tiempo.NanoSegundosTranscurridos();
	
	
	copia2 = original;
	tiempo.Reset();
	copia2.OrdenaInsercion();
	tiempo2 = tiempo.NanoSegundosTranscurridos();
	
	
	copia3 = original;
	tiempo.Reset();
	copia3.OrdenaIntercambio ();
	tiempo3 = tiempo.NanoSegundosTranscurridos();
	
	  
	copia4 = original;
	tiempo.Reset();
	copia4.OrdenaIntercambioMejorado ();
	tiempo4 = tiempo.NanoSegundosTranscurridos();

	cout << "Los tiempos de ejecucion han sido:" << endl
		  << "\tSeleccion:            " << tiempo1 << " ns" << endl
		  << "\tInsercion:            " << tiempo2 << " ns" << endl
		  << "\tIntercambio:          " << tiempo3 << " ns" << endl
		  << "\tIntercambio mejorado: " << tiempo4 << " ns" << endl;
	
	return 0;
}

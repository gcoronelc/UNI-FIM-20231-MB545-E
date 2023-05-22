// Creditos: ANTHONY RAMON PEREZ ANGOME

#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

// Servicios

int* crearArregloService(int n) {
	// Variables
	int* arreglo;
	// Proceso
	arreglo = new int[n];
	for (int i = 0; i < n; i++)
		arreglo[i] = rand() % 21;
	// Reporte
	return arreglo;
}

void mostrarArregloService(int* arreglo, string etiqueta, int tamanio) {
	// Proceso
	cout << etiqueta;
	for (int i = 0; i < tamanio; i++) {
		cout << arreglo[i] << " ";
	}
	cout << "\n";
}

int main() {
	// Variables
	int* arreglo1;
	int* arreglo2;
	int n;
	// Datos
	n = 10;
	// Generar arreglos
	srand(time(NULL));
	arreglo1 = crearArregloService(n);
	arreglo2 = crearArregloService(n);
	// Generando la suma

	// Reporte
	mostrarArregloService(arreglo1, "Arreglo 1: ", n);
	mostrarArregloService(arreglo2, "Arreglo 2: ", n);
	
	system("pause");
	return 0;
}
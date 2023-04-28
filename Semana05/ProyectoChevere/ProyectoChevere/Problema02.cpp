#include <iostream>
using namespace std;

float terminoN(int n) {
	// Variable
	float respuesta;
	// Proceso
	respuesta = 3.0 / n;
	// Reporte
	return respuesta;
}

float sumaN(int n) {
	// Variable
	float respuesta;
	// Proceso
	respuesta = 100;
	// Reporte
	return respuesta;
}

int main02() {
	// Variables
	int n;
	float termino, suma;
	// Datos
	cout << "Valor de N: ";
	cin >> n;
	// Proceso
	termino = terminoN(n);
	suma = sumaN(n);	
	// Reporte
	cout << "Trermino " << n << ": " << termino << "\n";
	cout << "Suma de " << n << " terminos: " << suma << "\n";
 	return 0;
}
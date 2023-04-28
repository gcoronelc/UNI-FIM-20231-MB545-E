/*
PROBLEMA 1
Desarrollar una función que determine si un número entero es primo o no lo es.
*/

#include <iostream>
using namespace std;

bool esPrimo(int numero) {
	// Variables
	bool respuesta;
	int  cont;
	// Proceso
	cont = 0;
	for (int i = 1; i <= numero; i++) {
		cont += (numero % i == 0) ? 1 : 0;
	}
	respuesta = (cont == 2);
	// Reporte
	return respuesta;
}

int main01() {

	cout << "PROBLEMA 1\n";

	for (int i = 1; i < 20; i++) {
		cout << i << " primo? " << esPrimo(i) << "\n";
	}

	return 0;
}
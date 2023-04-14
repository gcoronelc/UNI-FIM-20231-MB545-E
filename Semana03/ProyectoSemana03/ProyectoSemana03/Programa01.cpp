#include <iostream>
#include <cmath>
#include <locale>
#include <sstream>
using namespace std;

int main() {

	// Variables
	int n;
	long factorial;
	// Lectura
	cout << "Valor de n: "; cin >> n;
	// Validación
	if (n < 0) {
		cout << "\n";
		cout << "No existe factorial de un numero negativo.\n";
		return 0; // Finaliza el programa
	}
	// Proceso
	factorial = 1;
	while (n > 1) {
		factorial *= n--;
	}
	// Reporte
	cout << "Factorial: " << factorial << "\n";
	return 0;
}

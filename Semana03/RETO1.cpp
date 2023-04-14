//CREDITOS: RENZO INGA 20
#include <iostream>
#include <sstream>
using namespace std;
int main() {
	// Variables
	int m, n, resto;
	stringstream resultado; // Para el resultado
	// Lectura de datos
	cout << "LECTURA\n";
	cout << "==============================\n";
	cout << "Valor de m: "; cin >> m;
	cout << "Valor de n: "; cin >> n;
	// Proceso
	resultado << "Resultado: ";
	if (m <= n) {
		for (int i = m; i <= n; i++) {
			resto = i % 2;
			if (resto == 1) {
				resultado << " " << i;
			}
		}
	} else { 
		for (int i =m; i >=n; i--) {
			resto = i % 2;
			if (resto == 1) {
				resultado << " " << i;
			}
		}
	}
	// Reporte
	cout << "\n";
	cout << "REPORTE\n";
	cout << "==============================\n";
	cout << resultado.str();
	cout << "\n";
	// Fin
	return 0;
}

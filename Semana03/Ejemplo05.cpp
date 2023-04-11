/*
Factorial de n
*/

#include <iostream>
using namespace std;

int main(){

	// Variables
	int n;
	long factorial;
	// Lectura
	cout << "Valor de n: "; cin >> n;
	// Proceso
	factorial = 1;
	while(n>1){
		factorial *= n--;
	}
	// Reporte
	cout << "Factorial: " << factorial << "\n";
	return 0;
}

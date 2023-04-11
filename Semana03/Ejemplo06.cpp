/*
Mostrar los "n" terminos de la siguiente serie.
Serie: 2, 18, 50, 98, ...
Tambien se debe mostrar la suma de sus terminos.
*/

#include <iostream>
#include <cmath>
#include <locale>
#include <sstream>
using namespace std;

int main(){
	
	//Variables
	int n, suma; //Declarar variables
	stringstream serie;
	// Lectura
	cout << "Inserte el valor de n: ";
	cin >> n;
	// Proceso
	suma = 0;
	serie << "Serie: ";
	for(unsigned i = 1; i <= n; i++){
		int t = 2*pow(2*i-1,2);
		serie << t << " ";
		suma += t;
	}
	//Salida
	cout << serie.str() << "\n";
	cout << "La suma es: " << suma << "\n";
	return 0;
}


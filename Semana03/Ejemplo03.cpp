/*
Desarrollar un programa que les numeros
enteros positivos.
La lectura finaliza cuando se ingresa 
un valor negativo o cero.
El programa debe reportar el mayor y el 
menor de los numeros.
*/

#include <iostream>
using namespace std;

int main(){
	// Variables
	int numero, mayor, menor;
	bool flagPrimeraLectura;
	// Lectura y proceso
	flagPrimeraLectura = true;
	mayor = 0;
	menor = 0;
	do{
		cout << "Valor entero: "; cin >> numero;
		if(numero<=0){
			break;
		}
		if(flagPrimeraLectura){
			mayor = numero;
			menor = numero;
			flagPrimeraLectura = false;
			continue;
		}
		mayor = (numero>mayor)?numero:mayor;
		menor = (numero<menor)?numero:menor;
	} while(true);
	// Reporte
	cout << "Mayor: " << mayor << "\n";
	cout << "Menor: " << menor << "\n";
	return 0;
}

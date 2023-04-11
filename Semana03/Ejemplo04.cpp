/*
Desarrollar un programa que les numeros
enteros positivos.
La lectura finaliza cuando se ingresa 
un valor negativo o cero.
El programa debe reportar el mayor y el 
menor de los numeros.
*/

#include <iostream>
#include <sstream>
using namespace std;

int main(){
	// Variables
	int numero, mayor, menor, cantNumeros;
	stringstream datos;
	// Lectura
	cantNumeros = 0;
	do{
		cout << "Valor " << (cantNumeros+1) << ": "; 
		cin >> numero;
		if(numero<=0){
			break;
		}
		datos << " " << numero;
		cantNumeros++;
	} while(true);
	// proceso
	mayor = 0;
	menor = 0;
	for(int i=1; i <= cantNumeros; i++){
		datos >> numero;
		if(i==1){
			mayor = numero;
			menor = numero;
			continue;
		}
		mayor = (numero>mayor)?numero:mayor;
		menor = (numero<menor)?numero:menor;
	}
	// Reporte
	cout << "Mayor: " << mayor << "\n";
	cout << "Menor: " << menor << "\n";
	return 0;
}

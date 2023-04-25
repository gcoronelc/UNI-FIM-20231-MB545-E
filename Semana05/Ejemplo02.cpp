/*
Desarrollar una función que permita elevar un número a una potencia.
La base y el exponente deben ser números enteros.
No usar funciones matematicas.
*/
#include <iostream> 
using namespace std;
// CREDITOS: Kadhif Montenegro Contreras  
long potencia(int base,int exponente ){
	// Variables
	long pot;
	// Proceso
	pot=1;
	for(int i=1;i<=exponente;i++){
		pot*=base;
	}
	
	//Reporte
	return pot;
}
// CREDITOS: Kadhif Montenegro Contreras  
long potencia2(int base,int exponente ){
	if (exponente==0) return 1;
	else return base*potencia2(base,exponente-1);
}
int main() {
	cout<<"La potencia es igual a: "<<potencia(2,4)<<endl;
	cout<<"La potencia es igual a: "<<potencia2(2,4)<<endl;
	return 0;
}

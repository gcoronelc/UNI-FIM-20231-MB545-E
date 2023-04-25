/*
Desarrollar las siguientes funciones:
- Función fnMcd: Calcula el MCD de 2 numeros enteros.
- Función fnMcm: Calcula el MCM de 2 números enteros.
*/
#include <iostream> 
using namespace std;

// CREDITOS: Laynes Caire Marco 

int fnMcd( int n1, int n2){
	//Variable
	int mcd;
	//Proceso
	while(n1!=n2){
		if(n1>n2) n1=n1-n2;
		else n2=n2-n1;
	}
	mcd=n1;
	//Reporte
	return mcd;
}
int fnMcd2( int n1, int n2){
	//Variable
	int mcd;
	//Proceso
	mcd=1;
	for(int i=1; i<=min(n1,n2); i++){
	if((n1%i +n2%i)==0){
		mcd=i;
	}	
	}
	//Reporte
	return mcd;
}
int fnMcm( int n1, int n2){
	return n1*n2/fnMcd(n1,n2);
}
int main() {
	cout<<"El mcd es: "<< fnMcd(15,20)<<endl;
	cout<<"El mcm es: "<< fnMcm(15,20)<<endl;
	cout<<"El mcd es: "<< fnMcd2(15,20)<<endl;
	return 0;
}

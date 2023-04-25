/*
Desarrollar una función que permita encontrar el termino N de la serie de Fibonacci.
*/
#include <iostream> 
using namespace std;

// CREDITOS: Erick Cuadros 
long fibonacci(int n){
	if (n==1  || n==2 ) return 1;
	else return fibonacci(n-1)+fibonacci(n-2);
}

// CREDITOS: Pedro Izquierdo
long fibonacci2(int n){
	//Variables
	long terminoN, a, b ,c;
	//Procesos  
	a=1; b=1;terminoN=1;
	for (int i=3;i<=n; i++){
		c=a+b;
		terminoN=c;
		a=b;
		b=c;
	}
	//Reporte
	return terminoN;
}

// CREDITOS: Pedro Izquierdo
long fibonacci3(int n){
	//Variables
	long terminoN, a, b ,c;
	//Procesos  
	a=0; b=1;terminoN=1;
	for (int i=2;i<=n; i++){
		c=a+b;
		terminoN=c;
		a=b;
		b=c;
	}
	//Reporte
	return terminoN;
}

int main() {
	cout << "El termino 8 de fibonacci: " << fibonacci(10)<<"\n";
	cout << "El termino 8 de fibonacci2: " << fibonacci2(10)<<"\n";
	cout << "El termino 8 de fibonacci3: " << fibonacci3(10)<<"\n";
	return 0;
}



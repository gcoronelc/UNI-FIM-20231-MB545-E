/*
Desarrollar una función para calcular el factorial de N.
*/
#include <iostream> 
using namespace std;
// CREDITOS: Renzo Fabian Inga campos  
long factorial(int n ){
	// Variables
	long fac, i;
	// Proceso
	/*
	fac=1;
	for ( int i=1; i<=n ; i++){
		fac*=i;
	}*/
	for(i=1, fac=1;i<=n;fac*=i++);
	//Reporte
	return fac;
}
// CREDITOS: Renzo Fabian Inga campos  
long factorial2(int n ){
	// Variables
	long fac;
	// Proceso
	fac=1;
	while (n>0) fac*=n--;
	//Reporte
	return fac;
}
// CREDITOS: Renzo Fabian Inga campos  
long factorial3(int n ){
	if (n==0) return 1;
	else return n*factorial3(n-1);
}
int main() {
	cout << "factorial(7)= " << factorial(7) << "\n";
	cout << "factorial(7)= " << factorial2(7) << "\n";
	cout << "factorial(7)= " << factorial3(7) << "\n";
	return 0;
}


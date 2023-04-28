// Fabian

#include <iostream>
using namespace std;
double sumaN2(int n) {
	double suma;
	suma = 0;
	for (int i = 1; i <= n; i++) {
		suma = suma + pow(-1,i)*(3.0/(2*i));
	}
	return suma;
}
int main04() {
	int n;
	cout << "PROBLEMA 4\n";
	cout << "Introduzca el valor de n: "; 
	cin >> n ;
	cout << "La suma es " << sumaN2(n) << "\n";
	return 0;
}
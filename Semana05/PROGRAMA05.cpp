// Fabian

#include <iostream>
using namespace std;
double sumaN3(int n) {
	double suma;
	suma = 0;
	for (int i = 1; i <= n; i++) {
		suma = suma + (pow(3,i-1))/i;
	}
	return suma;
}
int main() {
	int n;
	cout << "PROBLEMA 5\n";
	cout << "Introduzca el valor de n: ";
	cin >> n;
	cout << "La suma es " << sumaN3(n) << "\n";
	return 0;
}
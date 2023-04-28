// Fabian

#include <iostream>
using namespace std;
double fnmayor(int x,int y) {
	double mayor;
	if (x > y) {
		mayor = x;
	}
	else {
		mayor = y;
	}
	return mayor;
}
int main06() {
	int x,y;
	cout << "PROBLEMA 5\n";
	cout << "Introduzca el valor de x: "; cin >> x;
	cout << "Introduzca el valor de y: "; cin >> y;
	cout << "El mayor de los numero es " << fnmayor(x,y) << "\n";
	return 0;
}
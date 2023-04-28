#include <iostream>

using namespace std;

double serierecur(int n){
	if (n == 1){
		return 3;
	} else
		return 3.0/n + serierecur(n-1);
}


int mainArturo() {
	//variables
	int n = 0;
	//datos
	cout << "N: ";
	cin >> n;	
	//proceso
	double resultado = serierecur(n);
	//reporte
	cout << "La suma de la serie es: " << resultado << endl;

	return 0;
}


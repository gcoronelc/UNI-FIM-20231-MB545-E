#include<iostream>
using namespace std;

float terminoN(float n) {
	// Variable
	float respuesta;
	//Proceso
	respuesta = 3.0 / n;
	//Reporte
	return respuesta;
}

int mainAnthony() {
	int n;
	cout << "PROBLEMA 2 \n";
	cout << "La serie: " << endl;
	cout << " 3/1 +3/2 + 3/3 + 3/4 + ... \n";
	cout << "Digite la cantidad de términos: ";cin >> n;

	for (int i = 1;i <= n;i++) {
		cout << terminoN(i) << " + ";
	}
	
	return 0;
}
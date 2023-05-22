#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

int main() {
	int x = 0, y = 0, N = 0;
	int limite_inferior = 10, limite_superior = 99;
	int cuadrante_1 = 0, cuadrante_2 = 0, cuadrante_3 = 0, cuadrante_4 = 0;
	float distancia = 0, suma_distancia = 0, promedio_distancia = 0;
	srand(time(NULL));
	do {
		cout << "Ingrese cantidad de elementos (N>0): "; cin >> N;
	} while (N <= 0);	
	cout << "\n\tX" << "\tY" << "\tDistancia" << endl;
	for (int i = 1; i <= N; i++) {
		x = (10 + rand() % (limite_superior - limite_inferior)) * pow(-1, (rand()));
		y = (10 + rand() % (limite_superior - limite_inferior)) * pow(-1, (rand()));
		distancia = sqrt(pow(x, 2) + pow(y, 2));
		suma_distancia += distancia;
		if (x > 0 && y > 0) { cuadrante_1++; }
		else if (x < 0 && y > 0) { cuadrante_2++; }
		else if (x < 0 && y < 0) { cuadrante_3++; }
		else if (x > 0 && y < 0) { cuadrante_4++; }
		cout << "\t" << x << "\t" << y << "\t" << distancia << endl;
	}
	cout << "\n\tCantidad de puntos en cada cuadrante:\n";
	cout << "\tCuadrante 1: " << cuadrante_1 << endl;
	cout << "\tCuadrante 2: " << cuadrante_2 << endl;
	cout << "\tCuadrante 3: " << cuadrante_3 << endl;
	cout << "\tCuadrante 4: " << cuadrante_4 << endl;
	promedio_distancia = suma_distancia / N;
	cout << "\n\tDistancia promedio: " << promedio_distancia << endl;
	system("pause");
	return 0;
}


#include <iostream> 
#include <sstream> 
#include <cmath>
using namespace std; 
int main() { 
	
	// Variables
	float promedio;
	int datos[][5] = {
		{15,14,12,12,16},
		{16,15,17,13,12},
		{13,18,16,16,13},
		{18,10,15,20,11}
	};
	
	string alumnos[] = {"Pedro","Juan","Fabian","Erick"};
	float promedios[4];
	
	// Proceso
	for(int i=0;i<=3;i++){
		promedio=0;
		for(int j=0; j<=4; j++){
			promedio += datos[i][j];
		}
		promedio /= 5.0;
		promedios[i]=promedio;
	}
	
	// Reporte
	for(int i=0; i<=3; i++){
		cout << "Estudiante: " << alumnos[i] << "\tPromedio: " << promedios[i];
		cout << "\t" << ceil(promedios[i]);
		cout << "\t" << floor(promedios[i]) << "\n";
	}
	
	return 0;
}	

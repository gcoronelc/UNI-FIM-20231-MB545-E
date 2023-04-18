#include <iostream> 
#include <sstream> 
using namespace std; 
int main() { 
	
	// Variables
	int promedio;
	int datos[][5] = {
		{15,14,12,12,0},
		{16,15,17,13,0},
		{13,18,16,16,0},
		{18,10,15,20,0}
	};
	
	string alumnos[] = {"Pedro","Juan","Fabian","Erick"};
	
	// Proceso
	for(int i=0;i<=3;i++){
		promedio=(datos[i][0]+datos[i][1]+datos[i][2]+datos[i][3])/4;
		datos[i][4]=promedio;
	}
	
	// Reporte
	for(int i=0; i<=3; i++){
		cout << "Estudiante: " << alumnos[i] << "\tPromedio: " << datos[i][4] << "\n";
	}
	
	return 0;
}	

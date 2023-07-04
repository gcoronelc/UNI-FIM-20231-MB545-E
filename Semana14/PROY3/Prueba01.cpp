#include <iostream>
#include "Logica..h"
using namespace std;


int main(){
	// Variables
	LogicaProyecto3 obj;
	float rptaEstudiante;
	// Proceso inicial
	obj.generaDatos();
	obj.calcArea();
	// Datos generados
	cout << "Base: " << obj.getBase() << endl;
	cout << "Altura: " << obj.getAltura() << endl;
	// Leer respuesta del estudiante
	cout << "Respuesta: "; 	cin >> rptaEstudiante;
	// Reporte
	cout << "Area correcta: " << obj.getArea() << endl;
	cout << "Estado: " << obj.validarRespuesta(rptaEstudiante);
	return 0;	
}

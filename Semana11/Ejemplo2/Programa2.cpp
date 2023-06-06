#include <iostream>
#include "ClaseAlumno.h"
using namespace std;

int main(){
	
	Alumno alu1;
	alu1.cargarDato("999|Juan|13|17");
	alu1.calcularPromedio();
	alu1.reporte();
	
	Alumno alu2 = Alumno(55,"Felix",17,10);
	alu2.calcularPromedio();
	alu2.reporte();
	
	Alumno alu3(56,"Sara",18,20);
	alu3.calcularPromedio();
	alu3.reporte();
	
}

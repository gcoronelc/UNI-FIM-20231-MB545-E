#include <iostream>
#include "ClasePersona.h"

int main() {
	
	Persona p1 = Persona(24,"Pedro");
	Persona arreglo[10];
	
	p1.leer();
	p1.correr();

	arreglo[0].correr();
}
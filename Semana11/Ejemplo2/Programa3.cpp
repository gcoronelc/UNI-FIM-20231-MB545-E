#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "ClaseAlumno.h"
using namespace std;

int n;
Alumno arreglo[200];
string archivoOrigen = "Datos.txt";
string archivoDestino = "Reporte.txt";

// Cargar el archivo en el arreglo
void cargarArchivo(){
	// Variable
	ifstream archivo;
	string texto;
	// Proceso
	n = 0;
	archivo.open(archivoOrigen,ios::in);
	while(!archivo.eof()){
		getline(archivo,texto);
		if(texto.length() >0){
			arreglo[n].cargarDato(texto);
			n++;
		}
	}
	archivo.close();
}

// Procesar datos
void procesarDatos(){
	for(int i = 0; i < n; i++){
		arreglo[n].calcularPromedio();
	}
}


// Generar reporte
void generarReporte(){
	ofstream archivo;
	string texto;
	archivo.open(archivoDestino, ios::out);
	for(int i = 0; i < n; i++){
		arreglo[i].calcularPromedio();
		texto = arreglo[i].toString();
		archivo << texto << "\n"; 
	}
	archivo.close();
}

int main(){
	cargarArchivo();
	procesarDatos();
	generarReporte();
	return 0;
}


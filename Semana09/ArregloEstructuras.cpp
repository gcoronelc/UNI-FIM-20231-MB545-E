#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

struct Estudiante{
	string nombre;
	int nota1;
	int nota2;
	float promedio;
	string condicion;
};

int main(){
	//Variable
	ofstream archivo;
	string nombArchivo = "Reporte.txt";
	
	// Configuracion
	setlocale(LC_CTYPE, "Spanish");
	wstring strW = L"ARREGLO DE ESTRUCTURAS";
	//SetConsoleTitle(strW.c_str());
	
	
	// Variables
	Estudiante lista[100];
	int contador;
	char rpta;
	int suma;
	float promedio;
	
	
	// Inicializar variables
	contador = 0;
	
	
	// Leer estudiantes
	do{
		
		cout << endl;
		cout << "ESTUDIANTE " << (contador + 1) << endl;
		cout << "=================================" << endl;
		cout << "Nombre: "; cin >> lista[contador].nombre;
		cout << "Nota 1: "; cin >> lista[contador].nota1;
		cout << "Nota 2: "; cin >> lista[contador].nota2;
		contador++;
		
		cout << endl;
		cout << "Hay otro estudiante (S/N): "; cin >> rpta; 
		
	} while( rpta == 'S' || rpta == 's');
	
	
	// Proceso
	suma=0;
	for(int i=0; i<contador; i++){
		lista[i].promedio = (lista[i].nota1 + lista[i].nota2) / 2;
		if(lista[i].promedio>10){
			lista[i].condicion="Aprobado";
		}
		else {
			lista[i].condicion="Desaprobado";
		}
		suma+=lista[i].promedio;
	}
	promedio=suma*1.0/contador;
	// Reporte
	cout << "PROGRAMACION ORIENTADA A OBJETOS" << endl;
	cout << "NRO \tNOMBRE\tNOTA1\tNOTA2\tPROM\tCONDICION " << endl;
	cout << "-----------------------------------------------------" << endl;
	for(int i=0; i<contador; i++){
		cout <<  (i+1) << "\t";
		cout <<  lista[i].nombre << "\t";
		cout <<  lista[i].nota1 << "\t";
		cout <<  lista[i].nota2 << "\t";
		cout <<  lista[i].promedio << "\t";
		cout <<  lista[i].condicion <<endl;
	}
	cout << "-----------------------------------------------------" << endl;	
	cout << "PROMEDIO DEL SALON:"<< promedio << endl;
	
	// Reporte a un archivo con formato personalizado: Reporte.txt
	
	archivo.open(nombArchivo, ios::out);

	archivo << "PROGRAMACION ORIENTADA A OBJETOS" << endl;
    archivo << "NRO \tNOMBRE\tNOTA1\tNOTA2\tPROM\tCONDICION " << endl;
	archivo << "-----------------------------------------------------" << endl;
	for(int i=0; i<contador; i++){
		archivo <<  (i+1) << "\t";
		archivo <<  lista[i].nombre << "\t";
		archivo <<  lista[i].nota1 << "\t";
		archivo <<  lista[i].nota2 << "\t";
		archivo <<  lista[i].promedio << "\t";
		archivo <<  lista[i].condicion <<endl;
	}
	archivo << "-----------------------------------------------------" << endl;	
	archivo << "PROMEDIO DEL SALON:"<< promedio << endl;
	
    archivo.close();
    
    
    
    
    // Reporte a un archivo con formato csv: Reporte.csv
	
	archivo.open("reporte.csv", ios::out);

    archivo << "NRO;NOMBRE;NOTA1;NOTA2;PROMEDIO;CONDICION" << endl;
	for(int i=0; i<contador; i++){
		archivo <<  (i+1) << ";";
		archivo <<  lista[i].nombre << ";";
		archivo <<  lista[i].nota1 << ";";
		archivo <<  lista[i].nota2 << ";";
		archivo <<  lista[i].promedio << ";";
		archivo <<  lista[i].condicion <<endl;
	}
	archivo << "PROMEDIO DEL SALON:"<< promedio << endl;
	
    archivo.close();
	return 0;
}

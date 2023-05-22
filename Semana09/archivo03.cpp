/*
Ejemplo que agrega datos a un archivo.
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int main(){

	// Variable
	ofstream archivo;
	string texto;
	char rpta;
	
	// Abrir el archivo para agregar nuevas lineas de testo
	archivo.open("datos.txt",ios::app);

	// Validar
	if(archivo.fail()){
		cout << "No se puede abrir el archivo." << endl;
		exit(1);
	}
	
	// Proceso
	do{
		// Datos
		cout << endl;
		cout << "Nueva linea para el archivo:" << endl;
		getline(cin, texto);

		archivo << texto << endl;
		// Consulta
		cout << endl;
		cout << "Mas datos (S/N)? "; 
		cin >> rpta;
		cin.ignore();
	} while( rpta == 'S' || rpta == 's');
	archivo.close();
	
	// Reporte desde el archivo
	ifstream archivo2;
	archivo2.open("datos.txt",ios::in);
	cout << endl;
	cout << "EL ARCHIVO" << endl;
	cout << "===============================================" << endl;
	while(!archivo2.eof()){
		getline(archivo2, texto);
		cout << texto << endl;
	}
	cout << endl;
	archivo2.close();
	
	return 0;
}

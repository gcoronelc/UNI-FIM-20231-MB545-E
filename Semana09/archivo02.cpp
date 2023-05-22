/*
Ejemplo para leer un archivo.
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int main(){

	// Variable
	ifstream archivo;
	string texto;
	string nombArchivo = "datos.txt";
	
	// Abrir el archivo en modo lectura
	archivo.open(nombArchivo,ios::in);

	// Validar
	if(archivo.fail()){
		cout << "No se puede abrir el archivo.\n";
		exit(1);
	}
	
	// Reporte desde el archivo
	while(!archivo.eof()){
		getline(archivo,texto);
		cout << texto << endl;
	}
	cout << endl;
	
	// Cerrar el archivo
	archivo.close();
	
	return 0;
}

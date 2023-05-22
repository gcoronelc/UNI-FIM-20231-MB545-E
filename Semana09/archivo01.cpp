/*
Ejemplo para crear un archivo.
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main() {

	// Variable
	ofstream archivo;
	string nombArchivo = "datos.txt";

	// Crea y abre el archivo
	archivo.open(nombArchivo, ios::out);

	// Validar
	if (archivo.fail()) {
		cout << "No se puede crear el archivo." << endl;
		exit(1);
	}

	// Reporte en archivo
	archivo << "Este es un ejemplo de archivo.\n";
	archivo << "Esto se pone bueno.\n";
	archivo << "Ahora todos mis datos iran a archivos.\n";

	// Cerrar el archivo
	archivo.close();

	// Fin
	cout << "Se ha creado el archivo: " << nombArchivo << "\n";
	cout << "Puedes revisar su contenido.\n";
	system("pause");
	return 0;
}

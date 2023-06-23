#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <fstream>
#include <string>
#include "libreria2023.h"

using namespace std;

class Parrafo {
private:
	int palabras = 0;
	int a = 0;
	int e = 0;
	int i = 0;
	int o = 0;
	int u = 0;
	string cadena = "";
	string parrafoInvertido = "";
	string cadenainvertida = "";
	vector <string> palabrasParrafo;
public:
	void lecturaDatos(string nombreArchivo) {
		// Variables
		ifstream archivo;
		string text;
		vector <string> lectura;
		int n = 0;
		// Abrir el archivo en modo lectura
		archivo.open(nombreArchivo, ios::in);
		// Validar
		if (archivo.fail()) {
			cout << "No se puede abrir el archivo.\n";
			exit(1);
		}
		// Reporte desde el archivo
		while (!archivo.eof()) {
			getline(archivo, text);
			cadena = text;
		}
		// Cerrar el archivo
		archivo.close();
	}
	void procesarDatos() {
		string subcadena = "";
		string s = "";
		for (int i = 0; i < cadena.size(); i++) {
			if ((cadena[i] == ' ' || cadena[i] == '.' || cadena[i] == ',' || cadena[i] == ';') and (subcadena.size() > 0)) {
				palabrasParrafo.push_back(subcadena);
				s.push_back(cadena[i]);
				palabrasParrafo.push_back(s);
				subcadena = "";
				s = "";
				palabras++;
				continue;
			}
			else if (cadena[i] != ' ' && cadena[i] != '.' && cadena[i] != ',' && cadena[i] != ';') {
				subcadena += cadena[i];
			}
			else {
				s.push_back(cadena[i]);
				palabrasParrafo.push_back(s);
				s = "";
			}
		}
		for (int j = 0; j < cadena.size(); j++) {
			if (cadena[j] == 'a' or cadena[j] == 'A') a++;
			if (cadena[j] == 'e' or cadena[j] == 'E') e++;
			if (cadena[j] == 'i' or cadena[j] == 'I') i++;
			if (cadena[j] == 'o' or cadena[j] == 'O') o++;
			if (cadena[j] == 'u' or cadena[j] == 'U') u++;
		}
		for (int i = cadena.size() - 1; i >= 0; i--) {
			cadenainvertida += cadena[i];
		}
		for (int i = palabrasParrafo.size() - 1; i >= 0; i--) {
			parrafoInvertido += palabrasParrafo[i];
		}
	}
	void reportarDatos(string nombreArchivo) {
		// Variables
		fstream archivo;
		// Abrir el archivo en modo lectura
		archivo.open(nombreArchivo, ios::out);
		// Validar
		if (archivo.fail()) {
			cout << "No se puede abrir el archivo.\n";
			exit(1);
		}
		// Reporte en archivo
		archivo << cadena << endl;
		archivo << "\nREPORTE:" << endl;
		archivo << "\nEl numero de palabras del parrafo es: " << palabras << endl;
		archivo << "El numero de vocales 'a' es de: " << a << endl;
		archivo << "El numero de vocales 'e' es de: " << e << endl;
		archivo << "El numero de vocales 'i' es de: " << i << endl;
		archivo << "El numero de vocales 'o' es de: " << o << endl;
		archivo << "El numero de vocales 'u' es de: " << u << endl;
		archivo << "\nCADENA INVERTIDA:\n" << endl;
		archivo << cadenainvertida << endl;
		archivo << "\nPARRAFO INVERTIDO:\n" << endl;
		archivo << parrafoInvertido;
		// Cerrar el archivo
		archivo.close();
	}
};

int main() {
	setlocale(LC_ALL, "");
	Parrafo parrafo;
	cout << "========================================\n";
	cout << "EXTRAYENDO DATOS...\n";
	parrafo.lecturaDatos("PROYECTO4-PARRAFO.txt");
	cout << "PROCESANDO DATOS...\n";
	parrafo.procesarDatos();
	cout << "REPORTANDO DATOS...\n";
	parrafo.reportarDatos("REPORTE_PARRAFO.txt");
	cout << "========================================\n";

	return 0;
}

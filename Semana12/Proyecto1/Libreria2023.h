// Libreria estandar del curso CPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

// Lee un entero
int leerEntero(string etiqueta) {
	int valor;
	cout << etiqueta; cin >> valor;
	return valor;
}

// Lee un entero desde un valor minimo
int leerEntero(string etiqueta, int valorMinimo) {
	int valor;
	do {
		cout << etiqueta; cin >> valor;
		if (valor < valorMinimo)
			cout << "Valor ingresado fuera de rango.\n";
	} while (valor < valorMinimo);
	return valor;
}

// Lee un entero desde un rango
int leerEntero(string etiqueta, int valorMinimo, int valorMaximo) {
	int valor;
	do {
		cout << etiqueta; cin >> valor;
		if (valor < valorMinimo || valor > valorMaximo)
			cout << "Valor ingresado fuera de rango.\n";
	} while (valor < valorMinimo || valor > valorMaximo);
	return valor;
}

vector<string> split(const string& cadena, char caracter) {
    // Variables
    vector<string> arreglo;
    int posicion;
    string datos;
    string dato;
    // Proceso
    datos = cadena;
    while (datos.size() > 0) {
        posicion = datos.find(caracter);
        if (posicion > 0) {
            dato = datos.substr(0, posicion);
            datos.erase(0, posicion + 1);
        }
        else {
            dato = datos;
            datos = "";
        }
        arreglo.push_back(dato);
    }
    return arreglo;
}

void creaMenu(string titulo, string opciones, char separador) {
    vector<string> arreglo = split(opciones,separador);
    string linea = "=================================\n";
    cout << titulo << "\n";
    cout << linea;
    for (int i = 0; i < arreglo.size(); i++)
        cout << arreglo[i] << "\n";
    cout << linea;
}

string leerCadena(string etiqueta) {
    string input;
    cout << etiqueta;
    cin.ignore();
    getline(cin,input);
    return input;
}

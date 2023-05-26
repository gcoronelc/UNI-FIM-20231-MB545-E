#include <iostream>
#include <windows.h>
#include <fstream>
#include "libreria2023.h"

using namespace std;

int main() {
	// Variables
	int algo, nota, precio, op;
	string frase;
	// Menu
	string titulo = "SISTEMA DE VENTAS";
	string opciones = "1 Opcion1,2 Opcion2,3 Opcion3,4 Salir";
	creaMenu(titulo,opciones, ',');
	op = leerEntero("Opcion: ", 1, 4);
	// Lectura
	fflush(stdin);
	frase = leerCadena("Ingresa una frase:"); 
	algo = leerEntero("Ingrese un numero entero: ");
	precio = leerEntero("Ingrese precio (>0): ", 1);
	nota = leerEntero("Ingre nota [0,20]: ",0,20);
	// Reporte
	cout << "\n";
	cout << "Valor ingresado: " << algo << "\n";
	cout << "Precio ingresado: " << precio << "\n";
	cout << "Nota ingresada: " << nota << "\n";
	cout << "Frase: " << frase << "\n";
	return 0;
}
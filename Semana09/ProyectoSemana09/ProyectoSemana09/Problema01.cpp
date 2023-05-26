#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "libreria2023.h"
using namespace std;

// Definiciones generales
struct Venta {
	string categoria;
	string descripcion;
	int participantes;
	double precio;
	double importe;
	double impuesto;
	double total;
	double comision;
};

vector<Venta> ventas;

// Rutinas utiles

double getPrecio(int categoria) {
	double precio = 0;
	switch (categoria) {
	case 1: precio = 800.0; break;
	case 2: precio = 500.0; break;
	case 3: precio = 1800.0; break;
	case 4: precio = 1000.0; break;
	}
	return precio;
}

int getPorcGanancia(int categoria, int participantes) {
	int porcGanancia = 0;
	porcGanancia = (categoria == 1) ? (participantes > 12 ? 7 : 5) : porcGanancia;
	porcGanancia = (categoria == 2) ? (participantes > 12 ? 5 : 3) : porcGanancia;
	porcGanancia = (categoria == 3) ? (participantes > 12 ? 10 : 8) : porcGanancia;
	porcGanancia = (categoria == 4) ? (participantes > 12 ? 6 : 4) : porcGanancia;
	return porcGanancia;
}

string getNombreCategoria(int categoria) {
	string scategoria = "None";
	switch (categoria) {
	case 1: scategoria = "Programacion"; break;
	case 2: scategoria = "Ofimatica"; break;
	case 3: scategoria = "Administracion"; break;
	case 4: scategoria = "Otros"; break;
	}
	return scategoria;
}

// Opciuones del menu

void menu01() {
	// Variables
	string categorias, descripcion;
	int catElegida, participantes, porcGanancia;
	Venta venta;
	// Datos
	categorias = "1. Programación,2. Ofimática,";
	categorias += "3. Administración,4. Otros";
	// Lectura
	creaMenu("CATEGORIA", categorias, ',');
	catElegida = leerEntero("Opcion [1,4]: ", 1, 4);
	descripcion = leerCadena("Descripcion: ");
	participantes = leerEntero("Cantidad de participantes (>0): ", 1);
	// Proceso
	venta.precio = getPrecio(catElegida);
	porcGanancia = getPorcGanancia(catElegida, participantes);
	venta.total = venta.precio * participantes;
	venta.importe = venta.total / 1.18;
	venta.impuesto = venta.total - venta.importe;
	venta.comision = venta.importe * porcGanancia / 100.0;
	venta.categoria = getNombreCategoria(catElegida);
	venta.descripcion = descripcion;
	venta.participantes = participantes;
	// Reporte
	cout << "\n";
	cout << "Categoria: " << venta.categoria << "\n";
	cout << "Importe: " << venta.importe << "\n";
	cout << "Impuesto: " << venta.impuesto << "\n";
	cout << "Total: " << venta.total << "\n";
	cout << "Comision: " << venta.comision << "\n";
}

void menu02() {
	cout << "Opcion 2";
}

void menu03() {
	cout << "Opcion 3";
}

void menu04() {
	cout << "Chau\n";
}

// Funcion principal
int main() {
	// Variables
	string titulo = "CURSOS PARA PROFESIONALES";
	string menu = "1. Registrar Venta,2. Listado de Ventas,3. Resumen de Ventas,4. Salir";
	int op;
	// Control del menu
	do {
		system("cls");
		creaMenu(titulo, menu, ',');
		op = leerEntero("Opcion: ", 1, 4);
		// Procesar menu
		system("cls");
		switch (op) {
		case 1: menu01(); break;
		case 2: menu02(); break;
		case 3: menu03(); break;
		case 4: menu04(); break;
		}
		system("pause");
	} while (op != 4);
	return 0;
}
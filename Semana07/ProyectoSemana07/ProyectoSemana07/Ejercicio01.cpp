// Creditos: ANTHONY RAMON PEREZ ANGOME

#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

// Variables de los indicadores
int cantTotalVentas = 0;
int cantClientesMasculinos2doDcto = 0;
int cantClientesFemeninos2doDcto = 0;
double sumaTotalVentas = 0.0;
double sumaTodosDescuentos = 0.0;
double suma2dosDescuentos = 0.0;

// Rutinas de proposito general

char leerSexo() {
	// Variables
	char sexo;
	// Proceso
	do {
		cout << "Sexo del cliente (M/F)?"; cin >> sexo;
		sexo = toupper(sexo);
		if (sexo != 'M' && sexo != 'F')
			cout << "Dato ingresado es incorrecto!!\n";
	} while (sexo != 'M' && sexo != 'F');
	// Reporte
	return sexo;
}

int leerEdad() {
	// Variables
	int edad;
	// Proceso
	do {
		cout << "Edad del cliente en años? "; cin >> edad;
		if (edad < 18 || edad > 120)
			cout << "Edad imposible!!\n";
	} while (edad < 18 || edad > 120);
	// Reporte
	return edad;
}

int  leerTipoHospedaje() {
	// Variables
	int op;
	// Proceso
	cout << "Tipo de hospedaje: \n";
	cout << "1.- Imperial \n";
	cout << "2.- VIP \n";
	cout << "3.- Gold \n";
	do {
		cout << "Opción: "; cin >> op;
		if (op < 1 || op>3)
			cout << "Opcion incorrecta!!\n";
	} while (op < 1 || op>3);
	// Reporte
	return op;
}

double obtenerPrecioDia(int tipo) {
	// Variables
	double precio;
	// Proceso
	precio = 0.0;
	precio = (tipo == 1) ? 150.0 : precio;
	precio = (tipo == 2) ? 260.0 : precio;
	precio = (tipo == 3) ? 350.0 : precio;
	// Reporte
	return precio;
}

double obtenerPorcDcto1(int tipo, int dias) {
	// Variables
	double porcentaje;
	// Proceso
	porcentaje = 0.0;
	porcentaje = (tipo == 1) ? (dias > 10 ? 8 : (dias > 4 ? 5 : porcentaje)) : porcentaje;
	porcentaje = (tipo == 2) ? (dias > 10 ? 10 : (dias > 4 ? 6 : porcentaje)) : porcentaje;
	porcentaje = (tipo == 3) ? (dias > 10 ? 14 : (dias > 4 ? 8 : porcentaje)) : porcentaje;
	// Reporte
	return porcentaje;
}

double obtenerPorcDcto2(char sexo, int edad) {
	// Variables
	double porcentaje;
	// Proceso
	porcentaje = 0.0;
	porcentaje = (sexo == 'M' && edad > 50) ? 5 : porcentaje;
	porcentaje = (sexo == 'F' && edad > 50) ? 7 : porcentaje;
	// Reporte
	return porcentaje;
}

// Modulos del menu

void mostrarMenu() {
	system("cls");
	cout << "LA CASA DEL INKA\n";
	cout << "==================================\n";
	cout << "SISTEMA DE VENTAS\n";
	cout << "Menú de opciones\n";
	cout << "==================================\n";
	cout << "1.- Procesar venta\n";
	cout << "2.- Reporte de ventas\n";
	cout << "3.- Salir\n";
	cout << "==================================\n";
}

int leerOpcion() {
	// Variables
	int op;
	// Proceso
	do {
		cout << "Opción: "; cin >> op;
		if (op < 1 || op>3) {
			cout << "Opcion incorrecta!!\n";
		}
	} while (op < 1 || op>3);
	// Reporte
	return op;
}

// Opcion 1: Lectura de datos
void menu01() {
	// Variables
	char sexo;
	int edad, tipoHospedaje, dias;
	double precioDia, porcDcto1, porcDcto2, importeBruto, descuento1, descuento2, importeNeto;
	// Lectura de datos
	sexo = leerSexo();
	edad = leerEdad();
	tipoHospedaje = leerTipoHospedaje();
	cout << "Cantidad de días: "; cin >> dias;
	// Datos previos
	precioDia = obtenerPrecioDia(tipoHospedaje);
	porcDcto1 = obtenerPorcDcto1(tipoHospedaje, dias);
	porcDcto2 = obtenerPorcDcto2(sexo, edad);
	// Calculo de la venta
	importeBruto = precioDia * dias;
	descuento1 = importeBruto * porcDcto1 / 100.0;
	descuento2 = importeBruto * porcDcto2 / 100.0;
	importeNeto = importeBruto - descuento1 - descuento2;
	// Reporte de la venta
	cout << "\n\n";
	cout << "RESULTADO DE LA VENTA\n";
	cout << "========================= \n";
	cout << "Precio por día: S/" << precioDia << "\n";
	cout << "Importe bruto: S/" << importeBruto << "\n";
	cout << "Descuento 1 (" << porcDcto1 << "%): S / " << descuento1 << "\n";
	cout << "Descuento 2 (" << porcDcto2 << "%): S / " << descuento2 << "\n";
	cout << "Importe neto: S/" << importeNeto << "\n";
	// Actualizar indicadores
	cantTotalVentas++;
	cantClientesMasculinos2doDcto += (sexo == 'M' && descuento2 > 0) ? 1 : 0;
	cantClientesFemeninos2doDcto += (sexo == 'F' && descuento2 > 0) ? 1 : 0;
	sumaTotalVentas += importeNeto;
	sumaTodosDescuentos += (descuento1 + descuento2);
	suma2dosDescuentos += descuento2;
}

// Opcion 2: Reporte de ventas
void menu02() {
	cout << "====================== \n";
	cout << "INDICADOR VALOR \n";
	cout << "====================== \n";
	cout << "Cantidad total de ventas: " << cantTotalVentas << "\n";
	cout << "Clientes masculinos con el segundo descuento: " << cantClientesMasculinos2doDcto << "\n";
	cout << "Clientes femeninos con el segundo descuento: " << cantClientesFemeninos2doDcto << "\n";
	cout << "Suma total de las ventas: S/" << sumaTotalVentas << "\n";
	cout << "Suma de todos los descuentos realizados: S/" << sumaTodosDescuentos << "\n";
	cout << "Suma de todos los segundos descuentos: S/" << suma2dosDescuentos << "\n";
}

// Opcion 3
void menu03() {
	cout << "Hasta luego :D \n";
}

int main() {
	// Variables del programa
	int op;
	// Control del menu
	do {
		// Capturar la opcion del menu
		mostrarMenu();
		op = leerOpcion();
		// Procesar la opcion del menu
		system("cls");
		switch (op) {
		case 1: menu01(); break;
		case 2: menu02(); break;
		case 3: menu03(); break;
		}
		// La pausa
		if (op != 3) system("pause");
	} while (op != 3);
	return 0;
}

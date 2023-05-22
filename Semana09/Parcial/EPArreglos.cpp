#include <iostream>
#include<stdlib.h>
using namespace std;

// Variables globales
int* VA = NULL;
int* VB = NULL;
int N = 0;

// Rutinas de proposito general

void limpiarMemoria() {
	if (VA == NULL) return;
	delete[] VA;
	delete[] VB;
	VA = NULL;
	VB = NULL;
}

int* generaVector(int N) {
	int* vector;
	vector = new int[N];
	for (int i = 0; i < N; i++) {
		vector[i] = rand() % 20 + 11;
	}
	return vector;
}

void mostrarVector(string etiqueta, int* vector) {
	cout << etiqueta;
	if (vector == NULL) {
		cout << "No hay vector!!\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (vector[i] == -1) break;
		cout << vector[i] << " ";
	}
	cout << "\n";
}

void agregarElemento(int* vector, int elemento) {
	for (int i = 0; i < N; i++) {
		if (vector[i] == elemento) break;
		if (vector[i] == -1) {
			vector[i] = elemento;
			break;
		}
	}
}

// Rutinas del menu

void mostrarMenu() {
	system("cls");
	cout << "MENU\n";
	cout << "1.- Genera vectores\n";
	cout << "2.- Vector interseccion\n";
	cout << "3.- Vector diferencia\n";
	cout << "4.- Finaliza el programa\n";
}

int leerOpcion() {
	// Variables
	int op;
	// Proceso
	do {
		cout << "Opcion: "; cin >> op;
		if (op < 1 || op>4) cout << "Opcion incorrecta!!\n";
	} while (op < 1 || op>4);
	// Reporte
	return op;
}

void menu1() {
	// lectura de N
	cout << "OPCION 1\n";
	do {
		cout << "Valor para N: "; cin >> N;
		if (N < 5) cout << "Ingrese un valor valido!!\n";
	} while (N < 5);
	// Proceso
	limpiarMemoria();
	VA = generaVector(N);
	VB = generaVector(N);
	// Reporte
	mostrarVector("Vector VA: ", VA);
	mostrarVector("Vector VB: ", VB);
}

void menu2() {
	// Control
	if (N == 0) {
		cout << "No ha generado los vectores!!\n";
		return;
	}
	// Variables
	int* VI = NULL;
	// Crear el vector intersecion con valores -1
	VI = new int[N];
	for (int i = 0; i < N; i++) {
		VI[i] = -1;
	}
	// Enconrar los valores comunes
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (VA[i] == VB[j]) {
				agregarElemento(VI, VA[i]);
			}
		}
	}
	// Reporte
	cout << "OPCION 2\n";
	mostrarVector("Vector VA: ", VA);
	mostrarVector("Vector VB: ", VB);
	mostrarVector("Vector VI: ", VI);
	delete[] VI;
}

void menu3() {
	// Control
	if (N == 0) {
		cout << "No ha generado los vectores!!\n";
		return;
	}
	// Variables
	int* VD = NULL;
	int cont;
	// Crear el vector diferencia con valores -1
	VD = new int[N];
	for (int i = 0; i < N; i++) {
		VD[i] = -1;
	}
	// Enconrar los elemento de la diferencia
	for (int i = 0; i < N; i++) {
		cont = 0;
		for (int j = 0; j < N; j++) {
			if (VA[i] == VB[j]) {
				cont++;
			}
		}
		if (cont == 0) agregarElemento(VD, VA[i]);
	}
	// Reporte
	cout << "OPCION 3\n";
	mostrarVector("Vector VA: ", VA);
	mostrarVector("Vector VB: ", VB);
	mostrarVector("Vector VD: ", VD);
	delete[] VD;
}
void menu4() {
	cout << "Fin del programa.\n";
}

int main() {
	// Variables
	int op;
	// Proceso principal
	do {
		// Menu de opciones
		mostrarMenu();
		op = leerOpcion();
		// Control del menu
		system("cls");
		switch (op) {
		case 1: menu1(); break;
		case 2: menu2(); break;
		case 3: menu3(); break;
		case 4: menu4(); break;
		}
		system("pause");
	} while (op != 4);
	// Fin
	limpiarMemoria();
	return op;
}
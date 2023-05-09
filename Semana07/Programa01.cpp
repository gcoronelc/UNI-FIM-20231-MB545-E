#include <iostream>
using namespace std;

// Variables Globales
int** matriz = NULL;
int filas, columnas;

// Modulos de proposito general

void liberarMemoria(){
	if(matriz!=NULL){
		for( int i=0; i<filas; i++ )
	  		delete[] matriz[i];
		delete[] matriz;		
	}
}

int leerEnteroPositivo(string etiqueta){
	// Variables
	int op;
	// Proceso
	do{
		cout << etiqueta; cin >> op;
		if(op<=0){
			cout << "El numero debe ser un valor positivo!!\n";
		}
	} while(op<=0);
	// Reporte
	return op;
}

void mostrarMatriz(){
	cout << "\nMATRIZ\n";
	for (int i = 0; i < filas; i++) {
		cout << "Fila " << i << ":\t";
		for(int j=0; j<columnas;j++){
			cout << matriz[i][j] << "\t";
		}
		cout << "\n";
	}
}

// Modulos del menu

void mostrarMenu(){
	system("cls");
	cout << "MENU\n";
	cout << "==================================\n";
	cout << "1.- Generar una matriz\n";
	cout << "2.- Obtener la suma de cada fila\n";
	cout << "3.- Obtener la suma de cada columna\n";
	cout << "4.- Suma de la TRIANGULAR superior\n";
	cout << "5.- Suma DE LA TRIANGULAR inferior\n";
	cout << "6.- Salir\n";
	cout << "==================================\n";
}

int leerOpcion(){
	// Variables
	int op;
	// Proceso
	do{
		cout << "Opcion: "; cin >> op;	
		if(op<1 || op>6){
			cout << "Opcion incorrecta!!\n";
		}
	} while(op<1 || op>6);
	// Reporte
	return op;
}

// Opcion 1: Generar la matriz
void menu01(){
	// Lectura de datos
	cout << "GENERAR MATRIZ\n\n";
	filas = leerEnteroPositivo("Filas: ");
	columnas = leerEnteroPositivo("Columnas: ");
	// Reservand el espacio
	liberarMemoria();
	matriz = new int*[filas];
	for (int i = 0; i < filas; i++) {
	    matriz[i] = new int[columnas];
	}
	// Generando los datos
	for (int i = 0; i < filas; i++) {
		for(int j=0; j<columnas;j++){
			matriz[i][j] = rand()%40 + 10;
		}
	}
	// Mostrar matriz
	mostrarMatriz();
}

// Opcion 2: Suma de filas
void menu02(){
	// Variables
	int* sumaFilas = new int[filas];
	// Proceso
	for (int i = 0; i < filas; i++) {
		sumaFilas[i] = 0;
		for(int j=0; j<columnas;j++){
			sumaFilas[i] += matriz[i][j];
		}
	}
	// Reporte
	mostrarMatriz();
	cout << "\n";
	for(int i=0; i<filas;i++){
		cout << "Fila " << i << ": " << sumaFilas[i] << endl;
	}
}

// Opcion 3
void menu03(){
	//Variables
	int* sumaColumnas = new int[columnas];
	//Proceso
	for (int j=0; j<columnas; j++){
		sumaColumnas[j]=0;
		for (int i=0; i<filas; i++){
			sumaColumnas[j] += matriz[i][j];
		}
	}
	//Reporte
	mostrarMatriz();
	for(int j=0; j<columnas; j++){
		cout << "Columna " << j << ": "<<sumaColumnas[j] << endl ; 
	}

}

// Opcion 4
void menu04(){
	// Validacion
	if(filas!=columnas || filas*columnas==0){
		cout << "La matriz debe ser cuadrada!!\n";
		return;
	}
	// Variables
	int suma;
	// Proceso
	suma = 0;
	for (int i = 0; i < filas; i++) {
		for(int j=0; j<columnas;j++){
			suma += (i<=j)?matriz[i][j]:0;
		}
	}
	// Reporte
	cout << "SUMA DE MATRIZ TRIANGULAR SUPERIOR\n\n";
	mostrarMatriz();
	cout << "\nSuma: " << suma << "\n";
}

// Opcion 5
void menu05(){
	// Validacion
	if(filas!=columnas || filas*columnas==0){
		cout << "La matriz debe ser cuadrada!!\n";
		return;
	}
	// Variables
	int suma;
	// Proceso
	suma = 0;
	for (int i = 0; i < filas; i++) {
		for(int j=0; j<columnas;j++){
			suma += (i>=j)?matriz[i][j]:0;
		}
	}
	// Reporte
	cout << "SUMA DE MATRIZ TRIANGULAR INFERIOR\n\n";
	mostrarMatriz();
	cout << "\nSuma: " << suma << "\n";

}

// Opcion 6
void menu06(){
	cout << "Chau!!\n";
}

int main(){
	// Variables del programa
	int op;
	// Control del menu
	do{
		// Capturar la opcion del menu
		mostrarMenu();
		op = leerOpcion();
		// Procesar la opcion del menu
		system("cls");
		switch(op){
			case 1: menu01(); break;
			case 2: menu02(); break;
			case 3: menu03(); break;
			case 4: menu04(); break;
			case 5: menu05(); break;
			case 6: menu06(); break;
		}
		// La pausa
		if(op!=6) system("pause");
	} while(op!=6);
	liberarMemoria();
	return 0;
}



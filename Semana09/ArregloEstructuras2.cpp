#include <iostream>
#include <string>
#include <windows.h>
#include "libreria.h"
using namespace std;


int main(){
	
	// Configuracion
	setlocale(LC_CTYPE, "Spanish");
	wstring strW = L"ARREGLO DE ESTRUCTURAS";
	//SetConsoleTitle(strW.c_str());

	
	// Proceso General
	do{
		procMenu();
		switch(opMenu){
			case 1:
				procRegistrarEstudiante();
				break;
			case 2:
				procListado();
				break;
			case 3:
				procEstadistico();
				break;
			case 4:
				cout << "Chau" << endl;
				break;											
		}
		cout << endl;
		system("pause");
	} while(opMenu != 4);
	
	system("pause");
	return 0;
}

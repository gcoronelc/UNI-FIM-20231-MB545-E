#include "Logica.h"
using namespace std;

int main(){
	
	// Variables
	string origen = "PROYECTO2-DATOS.TXT";
	string destino = "PROYECTO2-RESULTADO.TXT";
	Proyecto2 proyecto2 = Proyecto2(origen,destino);
	// Proceso
	cout << "Inicio del proceso...\n";
	if(proyecto2.cargarDatos() == -1){
		cerr << "Error en carga de datos.\n";
	};
	proyecto2.procesarDatos();
	proyecto2.generarReporte();
	cout << "Fin, todo bien.\n";

} 



#include "Logica.h"

int main(){
	
	Proyecto1 proyecto1;
	
	cout << "INICIO DEL PROCESO\n";
	cout << "Cargando los datos...\n";
	proyecto1.cargarDatos("PROYECTO1-DATOS.TXT");
	cout << "Procesando datos...\n";
	proyecto1.procesarDatos();
	cout << "Generando reporte...\n";
	proyecto1.generarReporte("PROYECTO1-RESULTADO.TXT");
	cout << "Fin, todo bien.\n";
}

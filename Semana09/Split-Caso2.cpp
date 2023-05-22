#include <iostream>
#include <string>
using namespace std;
int main(int argc, char ** argv) {
	
	string datos = "10,30,50,60,80";
	string datos_copia = datos;
	string dato;
	int numero, posicion, suma;
	
	suma = 0;
	while( datos.size() > 0){
		posicion = datos.find(",");
		if(posicion > 0){
			dato = datos.substr(0, posicion);
			datos.erase(0, posicion + 1);
		} else {
			dato = datos;
			datos = "";
		}
		suma += stoi(dato);
	}
	
	cout << "Datos: " << datos_copia << endl;
	cout << "Suma: " << suma << endl;
	return 0;	
}

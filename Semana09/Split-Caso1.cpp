#include <iostream>
using namespace std;
int main(int argc, char ** argv) {
	
	string datos = "12,54,23,54,67,89,12,34";
	string dato;
	int numero;
	int posicion;
	
	
	while( datos.size() > 0){
		posicion = datos.find(",");
		if(posicion > 0){
			dato = datos.substr(0, posicion);
			datos.erase(0, posicion + 1);
		} else {
			dato = datos;
			datos = "";
		}
		cout << "Dato: " << dato << endl;
	}
	
	return 0;	
}

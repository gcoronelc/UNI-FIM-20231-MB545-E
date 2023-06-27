/*
En este programa se ve la herencia en un ejemplo sencillo.
La clase hija puede crear sus propios metodos ampliando la funcionalidad.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class Clase1{
	
	private:
		
		string nombre;
	
	public:
		Clase1(){
			nombre = "Gustavo Coronel";
		}
		
		Clase1(string nombre){
			this->nombre = nombre;
		}
		
		void setNombre(string nombre){
			this->nombre = nombre;	
		}
		
		int sumar(int n1, int n2){
			return (n1+n2);
		}
		void mostrarDatos(){
			cout << "Nombre: " << nombre << "\n";
		}
	
};

class Clase2 : public Clase1{
	
	private:
		
		int edad;
	
	public:
		
		Clase2():Clase1("Claudia"){
			edad = 20;
		}
		
		Clase2(string nombre, int edad){
			this->setNombre(nombre);
			this->edad = edad;
		}
		
		int producto(int n1, int n2){
			return (n1*n2);
		}
		
		void mostrarDatos(){
			Clase1::mostrarDatos(); // Accede al metodo mostrarDatos del padre.
			cout << "Edad: " << edad << "\n";
		}
	
};

int main(){

	Clase2 objeto("Fabian",20);
	
	objeto.mostrarDatos();
	cout << "6 + 7 = " << objeto.sumar(6,7) << endl;
	cout << "6 * 7 = " << objeto.producto(6,7) << endl;
	
	system("pause");
	return 1;
}

#include <iostream>
using namespace std;

class Persona {
private:
	int edad;
	string nombre;
public:
	Persona(); // Constructor por defecto
	Persona(int, string); // Constructor adicional
	void leer();
	void correr();
};

Persona::Persona() {
	this->nombre = "Gustavo";
	this->edad = 50;
}
Persona::Persona(int _edad, string _nombre) {
	edad = _edad;
	nombre = _nombre;
}

void Persona::leer() {
	cout << "Soy " << nombre << " y estoy leyendo un libro.\n";
}

void Persona::correr() {
	cout << "Soy " << nombre << ", estoy corriendo una maraton y tengo " << edad << " anios.\n";
}

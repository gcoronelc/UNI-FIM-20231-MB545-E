#include <iostream>
#include "Libreria2023.h"
using namespace std;

class Alumno{
	
	private:
		
		int id;
		string nombre;
		int nota1;
		int nota2;
		int promedio;
		string condicion;
		
	public:
		
		// Constructor por defecto
		Alumno(){
			this->id = 0;
			this->nombre = "";
			this->nota1 = 0;
			this->nota2 = 0;
			this->promedio = 0;
			this->condicion = "";
		}
	
		// Constructor con parametros
		Alumno(int id, string nombre, int nota1, int nota2){
			this->id = id;
			this->nombre = nombre;
			this->nota1 = nota1;
			this->nota2 = nota2;
			this->promedio = 0;
			this->condicion = "";
		}
		
		// Calcular promedio
		void calcularPromedio(){
			int pr = (this->nota1 + this->nota2)/2;
			string condicion = (pr>=10)?"APROBADO":"DESAPROBADO";
			this->promedio = pr;
			this->condicion = condicion;
		}
		
		// Cargar datos desde una cadena
		// Por ejemplo: "500|Raul|15|18"
		void cargarDato(string datos){
			vector<string> arreglo = split(datos,'|');
			this->id = stoi(arreglo[0]);
			this->nombre = arreglo[1];
			this->nota1 = stoi(arreglo[2]);
			this->nota2 = stoi(arreglo[3]);
			this->promedio = 0;
			this->condicion = "";
		}
		
		// Mostrar reporte del objeto
		void reporte(){
			cout << "\n";
			cout << "ID: " << this->id << "\n";
			cout << "NOMBRE: " << this->nombre << "\n";
			cout << "NOTA 1: " << this->nota1 << "\n";
			cout << "NOTA 2: " << this->nota2 << "\n";
			cout << "PROMEDIO: " << this->promedio << "\n";
			cout << "CONDICION: " << this->condicion << "\n";
		}
		
		// Convierte el objeto en una cadena
		string toString(){
			string cadena = to_string(this->id) + "|";
			cadena += this->nombre + "|";
			cadena += to_string(this->nota1) + "|";
			cadena += to_string(this->nota2) + "|";
			cadena += to_string(this->promedio) + "|";
			cadena += this->condicion;
			return cadena;
		}
		
		
};

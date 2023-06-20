#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include "Libreria2023.h"

using namespace std;

class Proyecto2{
	
	private:
		
		struct Cuadrilatero{
			int item=0;
			int base1=0;
			int base2=0;
			int altura=0;
			string tipo="-";
			double perimetro=0;
			double area=0.0;
		};
		
		vector<Cuadrilatero> lista;
		string archivoOrigen;
		string archivoDestino;
		
		string obtenerTipo(Cuadrilatero o){
			string tipo = "NO SE";
			if(o.base1==o.base2 && o.base2== o.altura){
				tipo = "CUADRADO";
			} else if(o.base1 == o.base2 && o.base1 != o.altura){
				tipo = "RECTANGULO";
			} else {
				tipo = "TRAPECIO";
			}
			return tipo;			
		}
		
		double obtenerPerimetro(Cuadrilatero o){
			double d = abs(o.base1 - o.base2)/2.0;
			double h = pow(pow(d,2) + pow(o.altura,2),0.5);
			return o.base1 + o.base2 + o.altura + h;
		}
		
		double obtenerArea(Cuadrilatero o){
			return ((o.base1+o.base2)/2.0)*o.altura;
		}
		
	public:
		
		Proyecto2(string origen, string destino){
			this->archivoOrigen = origen;
			this->archivoDestino = destino;
		}
		
		int cargarDatos(){
			// Variable
			ifstream archivo;
			string texto;
			int control = 1;
			// Abrir el archivo en modo lectura
			archivo.open(archivoOrigen,ios::in);
			// Validar
			if(archivo.fail()){
				return -1;
			}
			// Cargar datos
			while(!archivo.eof()){
				getline(archivo,texto);
				if(control == 1){
					control = 0;
					continue;
				}
				vector<string> rec = split(texto,'|');
				Cuadrilatero obj;
				obj.item = stoi(rec[0]);
				obj.base1 = stoi(rec[1]);
				obj.base2 = stoi(rec[2]);
				obj.altura = stoi(rec[3]);
				lista.push_back(obj);
			}
			// Cerrar el archivo
			archivo.close();
		}
		
		void procesarDatos(){
			for(int i=0; i<lista.size(); i++){
				lista[i].tipo = obtenerTipo(lista[i]);
				lista[i].perimetro = obtenerPerimetro(lista[i]);
				lista[i].area = obtenerArea(lista[i]);
				
			}
		}
		
		
		
		int generarReporte(){
			// Variable
			ofstream archivo;
			// Crea y abre el archivo
			archivo.open(archivoDestino, ios::out);
			// Validar
			if (archivo.fail()) {
				return -1;
			}
			// Generar reporte
			archivo << "ITEM|BASE1|BASE2|ALTURA|TIPO|PERIMETRO|AREA\n";
			for(Cuadrilatero o: lista){
				archivo << o.item << "|" << o.base1 << "|";
				archivo << o.base2  << "|" << o.altura << "|";
				archivo << o.tipo << "|" << o.perimetro;
				archivo << "|" << o.area << "\n";
			}
			// Cerrar el archivo
			archivo.close();
		
		}
	
};




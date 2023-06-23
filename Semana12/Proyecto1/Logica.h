#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include "Libreria2023.h"
using namespace std;

class Proyecto1{
	
	private:
		
		struct Triangulo{
			int id = 0;
			int lado1 = 0;
			int lado2 = 0;
			int lado3 = 0;
			string estado = "Ok";
			string tipo = "Buen tipo";
			string perimetro = "-";
			string area = "-";
		};
		vector<Triangulo> lista;
		int contadorInv = 0;
		int contadorEsc = 0;
		int contadorEqu = 0;
		int contadorIso = 0;
		
		string  obtenerEstado(Triangulo o){
			string estado = "VALIDO";
			if( o.lado1 <= abs(o.lado2-o.lado3) || o.lado1 >= (o.lado2 + o.lado3)){
				estado = "INVALIDO";
			}
			if( o.lado2 <= abs(o.lado1-o.lado3) || o.lado2 >= (o.lado1 + o.lado3)){
				estado = "INVALIDO";
			}
			if( o.lado3 <= abs(o.lado1-o.lado2) || o.lado3 >= (o.lado1 + o.lado2)){
				estado = "INVALIDO";
			}
			return estado;
		}
		
		string obtenerTipo(Triangulo o){
			if (o.estado=="INVALIDO"){
				contadorInv++;
				return "-";
			}
			string tipo = "ESCALENO";
			if( o.lado1 == o.lado2 and o.lado2== o.lado3 ){
				tipo = "EQUILATERO";
				contadorEqu++;
			}
			else if( o.lado1 == o.lado2 || o.lado1 == o.lado3 || o.lado2 == o.lado3 ){
				tipo = "ISOCELES";
				contadorIso++;
			}
			else contadorEsc++;
			return tipo;
		}
		string obtenerPerimetro(Triangulo o){
			if (o.estado=="INVALIDO"){
				return "-";
			}
			int perimetro;
			perimetro = o.lado1 + o.lado2 + o.lado3;
			return to_string(perimetro);
		}
		string obtenerArea(Triangulo o){
			if (o.estado=="INVALIDO"){
				return "-";
			}
			double area, sp;
			sp = stoi(o.perimetro)/2;
			area = sqrt(sp*(sp-o.lado1)*(sp-o.lado2)*(sp-o.lado3));
			return to_string(area);
		}
	public:
		int cargarDatos(string nombreArchivo){
			// 0: Variables
			ifstream archivo;
			string texto;
			vector<string> arregloDatos;
			int n=1;
			// 1: Abrir el archivo
			archivo.open(nombreArchivo,ios::in);
			// 2: Validar
			if(archivo.fail()){
				return -1;
			}
			// 3: Procesar archivo
			while(!archivo.eof()){
				getline(archivo,texto);
				if(n==1){
					n=0;
					continue;
				}
				cout << texto << "\n";
				arregloDatos = split(texto,'|');
				Triangulo objeto;
				objeto.id = stoi(arregloDatos[0]);
				objeto.lado1 = stoi(arregloDatos[1]);
				objeto.lado2 = stoi(arregloDatos[2]);
				objeto.lado3 = stoi(arregloDatos[3]);
				lista.push_back(objeto);
			}
			// Cerrar el archivo
			archivo.close();
			return 1;
		}
		
		void procesarDatos(){
			for(int i=0; i<lista.size();i++){
				lista[i].estado = obtenerEstado(lista[i]);
				lista[i].tipo = obtenerTipo(lista[i]);
				lista[i].perimetro = obtenerPerimetro(lista[i]);
				lista[i].area = obtenerArea(lista[i]);
			}
		}
	
		int generarReporte(string nombreArchivo){
			// Variable
			ofstream archivo;
			// Crea y abre el archivo
			archivo.open(nombreArchivo, ios::out);
			// Validar
			if (archivo.fail()) {
				return -1;
			}
			// Cargar datos al archivo
			archivo << "ITEM|LADO1|LADO2|LADO3|ESTADO|TIPO|PERIMETRO|AREA\n";
			for(Triangulo o: lista){
				archivo << o.id << "|" << o.lado1 << "|" << o.lado2;
				archivo << "|" << o.lado3 << "|" << o.estado << "|";
				archivo << o.tipo << "|" << o.perimetro << "|";
				archivo << o.area << "\n";
			}
			// Resumen
			archivo << "RESUMEN:\n";
			archivo << "Triangulos invalidos: " << contadorInv << endl;
			archivo << "Triangulos escalenos: " << contadorEsc << endl;
			archivo << "Triangulos equilateros: " << contadorEqu << endl;
			archivo << "Triangulos isoceles: " << contadorIso << endl;
			
			// Cerrar el archivo
			archivo.close();
			
			return 1;
		}
	
	
};



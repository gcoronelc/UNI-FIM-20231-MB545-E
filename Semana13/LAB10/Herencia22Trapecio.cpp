/*
En este ejemplo se ilustra la sobre-escritura de metodos.
La clase Cuadrado hereda de la clase Cuadrilatero y sobre-escribe los métodos 
calcularPerimetro y calculaArea.
La clase Rectangulo hereda de la clase Cuadrilatero y sobre-escribe los 
métodos calcularPerimetro y calculaArea.
La clase TrapecioRectangulo hereda de la clase Cuadrilatero y sobre-escribe 
los métodos calcularPerimetro y calculaArea.
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Cuadrilatero{
	public:
		Cuadrilatero(){
		}
		virtual float calcularPerimetro() = 0; // método abstracto
		virtual float calculaArea() = 0; // método abstracta
};

class Cuadrado : public Cuadrilatero{
	private:
		
		float lado;
	
	public:
		Cuadrado(float _lado){
			lado = _lado;
		}
		float calcularPerimetro(){
			return 4*lado;
		}
		float calculaArea(){
			return lado * lado;
		}
};


class Trapecio : public Cuadrilatero{
	private:
		
		float altura; 
		float base1;
		float base2;
	
	public:
		Trapecio(float _altura, float _base1, float _base2){
			altura = _altura;
			base1 = _base1;
			base2 = _base2;
		}
		float calcularPerimetro(){
			float hipotenusa;
			hipotenusa= sqrt(pow((base2-base1),2)+pow(altura,2));
			return altura+base1+base2+hipotenusa;
		}
		
		float calculaArea(){
			float area=((base2+base1)*altura)/2;
			return area;
		}
};

int main(){
	
	Trapecio obj1(3,4,8);
	cout << "Perimetro: " << obj1.calcularPerimetro() << endl;
	cout << "Area: " << obj1.calculaArea() << endl;
	
	Cuadrilatero* arreglo[5];
	arreglo[0] = new Trapecio(6,6,6);
	cout << endl;
	cout << "Perimetro: " << arreglo[0]->calcularPerimetro() << endl;
	cout << "Area: " << arreglo[0]->calculaArea() << endl;
	
	system("pause");
	return 0;
}

/*
En este ejemplo se ilustra la sobre-escritura de metodos.
La clase Cuadrado hereda de la clase Cuadrilatero y sobre-escribe los m�todos 
calcularPerimetro y calculaArea.
La clase Rectangulo hereda de la clase Cuadrilatero y sobre-escribe los 
m�todos calcularPerimetro y calculaArea.
La clase TrapecioRectangulo hereda de la clase Cuadrilatero y sobre-escribe 
los m�todos calcularPerimetro y calculaArea.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class Cuadrilatero{
	public:
		Cuadrilatero(){
		}
		virtual float calcularPerimetro() = 0; // m�todo abstracto
		virtual float calculaArea() = 0; // m�todo abstracta
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

class Rectangulo : public Cuadrilatero{
	private:
		float altura;
		float base;
	
	public: 
			Rectangulo(float _base, float _altura){
				base=_base;
				altura=_altura;
			}
			float calcularPerimetro(){
				return (2*base + 2*altura);
			}
			float calculaArea(){
				return (base*altura);
			}
};



int main(){
	
	Cuadrado obj1(7);
	cout << "Perimetro: " << obj1.calcularPerimetro() << endl;
	cout << "Area: " << obj1.calculaArea() << endl;
	
	Cuadrilatero* arreglo[5];
	arreglo[0] = new Cuadrado(6);
	cout << endl;
	cout << "Perimetro: " << arreglo[0]->calcularPerimetro() << endl;
	cout << "Area: " << arreglo[0]->calculaArea() << endl;
	
	Rectangulo obj2(7,3);
	cout << "Perimetro: "<< obj2.calcularPerimetro()<<endl;
	cout << "Area: "<< obj2.calculaArea()<<endl;
	
	system("pause");
	return 0;
}

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class LogicaProyecto3{
	
	private:
		float base;
		float altura;
		float area;
		
	public:
		
		float getBase(){
			return this->base;
		}
		
		float getAltura(){
			return this->altura;
		}
		
		float getArea(){
			return this->area;
		}
		
		void generaDatos(){
			srand(time(NULL));
			base = 1 + rand()%20;
			altura = 1 + rand()%20;
		}
		
		void calcArea(){
			area = (base*altura)/2;
		}
		
		bool validarRespuesta(float respEstudiante){
			return (this->area == respEstudiante);
		}
	
};

//Victor Arturo Iba�ez Aliaga

#include <cmath>
#include <string>

#pragma once

class Triangle {
private:

	//lados del tri�ngulo
	double a, b, c;
	
public:

	//constructor
	Triangle(double _a, double _b, double _c) {
		this->a = _a;
		this->b = _b;
		this->c = _c;
	}

	//getters
	double get_a() {
		return this->a;
	}
	double get_b() {
		return this->b;
	}
	double get_c() {
		return this->c;
	}

	//determina si el tri�ngulo existe o no existe
	bool valid() {
		if (std::abs(this->a - this->b) < c and c < this->a + this->b and
			std::abs(this->b - this->c) < a and a < this->b + this->c and
			std::abs(this->a - this->c) < b and b < this->a + this->c) return true;
		else return false;
	}

	//retorna el per�metro del tri�ngulo
	double perim() {
		return this->a + this->b + this->c;
	}

	//retorna el �rea del tri�ngulo
	double area() {
		double p = (this->a + this->b + this->c) / 2;
		return std::pow(p*(p-this->a)*(p - this->b)*(p - this->c), 0.5);
	}

	//retorna -1 para tri�ngulos inv�lidos
	//retorna 0 para tri�ngulos equil�teros
	//retorna 1 para tri�ngulos is�celes
	//retorna 2 para tri�ngulos escalenos
	int tipo() {
		if (this->valid() == false) return -1;
		if (this->a == this->b and this->a == this->c and this->c == this->b) return 0;
		if (this->a == this->b or this->a == this->c or this->c == this->b) return 1;
		return 2;
	}

};
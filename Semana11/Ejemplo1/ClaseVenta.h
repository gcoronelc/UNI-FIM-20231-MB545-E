#include <iostream>
using namespace std;

class Venta {
private:
	int cantidad;
	float precio;
	float importe;
	float impuesto;
	float total;
public:
	Venta() {
		this->precio = 100;
		this->cantidad = 8;
	}

	Venta(int cantidad, float precio) {
		this->cantidad = cantidad;
		this->precio = precio;
	}

	void Procesar() {
		this->total = this->cantidad * this->precio;
		this->importe = this->total / 1.18;
		this->impuesto = this->total - this->importe;
	}

	float GetImporte() {
		return this->importe;
	}

	float GetImpuesto() {
		return this->impuesto;
	}

	float GetTotal() {
		return this->total;
	}
};

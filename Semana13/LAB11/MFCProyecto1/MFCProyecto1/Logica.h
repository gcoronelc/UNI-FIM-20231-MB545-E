#pragma once

class Venta {

public:

	float calcTotal(float precio, int cantidad) {
		return (precio * cantidad);
	}

	float calcImporte(float total) {
		return (total / 1.18);
	}

	float calcImpuesto(float total, float importe) {
		return(total - importe);
	}

};
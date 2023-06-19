#include <iostream>
#include "ClaseVenta.h";
using namespace std;

int main() {

	Venta venta1 = Venta(7,67);

	venta1.Procesar();

	cout << "Importe: " << venta1.GetImporte() << "\n";
	cout << "Impuesto: " << venta1.GetImpuesto() << "\n";
	cout << "Total: " << venta1.GetTotal() << "\n";

}
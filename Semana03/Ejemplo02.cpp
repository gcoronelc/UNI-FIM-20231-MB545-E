/*
Desarrollar un programa que muestre los numeros
multiplos de 3 entre m y n. (m>n)
*/
#include <iostream>
#include <sstream>
using namespace std;

int main(){
	// Varoables
	int m, n;
	stringstream resultado;
	// Datos
	cout<<"Inserta m (m>n): "; cin>>m;
	cout<<"Inserta n: "; cin>>n;
	// Proceso
	resultado << "Resultado: ";
	for (int i=n; i<=m; i++){
		if (i%3==0){
			resultado << i << "\t";
		}
	}
	// Reporte
	cout << resultado.str() << "\n";
	return 0;
}

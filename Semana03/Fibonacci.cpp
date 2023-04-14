// creditos: nai esteban jota 
// desarrollar un prograna que muestre n terminos de la serie de fibonacci.
#include <iostream>
#include <sstream>
using namespace std;
int main() {
    //variables 
    int i,n,a=0,b=1,c=0;
    stringstream serie;
    //lectura de datos
    cout<< "Numero de valor de la serie de fibonacci: "; cin >> n;
    //proceso
    serie << "Serie: 1 ";
    for (int i=1;i<n;i++){
	    c=a+b;
	    serie << c << " ";
	    a=b;
	    b=c;
    }
    // Reporte
	cout<< " \n";
	cout << serie.str() << "\n";
	cout<< "El termino enesimo: " << c;
    //reporte
    return 0;
}


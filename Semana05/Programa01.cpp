/*
PARAMETRO POR VALOR
*/

#include <iostream> 
using namespace std;

void incremento(int numero){
	numero++;
}

int main() {
	int dato = 50;
	cout << "Dato: " << dato << endl;
	incremento(dato);
	cout << "Dato: " << dato << endl;
	return 0;
}

#include <iostream> 
#include <sstream> 
using namespace std; 
int main() { 
	
	// Variables
	int datos[] = {65,34,76,45,98,23};
	
	// Mostrar datos de forma indexada
	for(int i=0;i<=5;i++){
		if(i==3) continue;
		cout << datos[i] << "\t";
	}
	cout << "\n";
	
	// Mostrar datos de forma indexada
	for(int i=0;i<=5;i+=2){
		if(i==3) continue;
		cout << datos[i] << "\t";
	}
	cout << "\n";
	
	// Mostrar datos de forma colección
	for(int item: datos){
		cout << item << "\t";
	}
	

	return 0;
}

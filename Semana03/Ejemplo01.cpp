/*
Desarrollar un programa que muestre los numeros
multiplos de 3 entre m y n. (m>n)

Solucion de: Joseph Mori Marchena y Arturo Diaz
*/
#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){

	int m, n;
	cout<<"Inserta m (m>n)"; cin>>m;
	cout<<"Inserta n"; cin>>n;

	for (int i=n; i<=m; i++){
		if (i%3==0){
			cout<<i<<endl;
		}
	}
	
	return 0;
}

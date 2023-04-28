// Felix Huamanchumo Ramos
// SERIE: (3/1)+(3/2)+(3/3)+(3/4)+...+(3/N)
#include<iostream>
#include<math.h>
using namespace std;

float terminoENE(int n)
{
	//VARIABLE
	float respuesta;

	//PROCESO
	respuesta = 3.0 / n;

	//REPORTE
	return respuesta;
}

float sumaAbc(int n)
{
	//VARIABLE
	float respuesta_sum;

	//PROCESO
	respuesta_sum = 0;
	for (int i = 1; i <= n; i++)
	{
		respuesta_sum = respuesta_sum + (3.0 / i);
	}

	//REPORTE
	return respuesta_sum;
}

int mainHuamanchumo()
{
	int N;
	float Tn, Sn;
	cout << "Ingrese la cantidad de terminos: "; cin >> N;
	Tn = terminoENE(N);
	Sn = sumaAbc(N);
	cout << "El termino enesimo sera: " << Tn << endl;
	cout << "La suma hasta el termino enesimo sera: " << Sn << endl;
	return 0;
}
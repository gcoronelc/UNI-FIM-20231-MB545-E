/*
	P1
	Resolver (seno(x)-cos(x))/raiz2(x)
*/

#include<iostream>
#include<stdlib.h>
#include<math.h>
#define pi 2*asin(1.0)
#define k pi/180
using namespace std;

void leeN(double& N) {
	cout << "N= "; cin >> N;
}

void leex(float& x) {
	cout << "x= "; cin >> x;
}

long double facto(double N) {
	if (N == 0 || N == 1)
		return(1);
	else
	return(N * facto(N - 1));
}

double radian(double N, float x) {
	return(x * k);
}

double seno(double N, float x) {
	double S = 0; int i;
	for (i = 1; i <= N; i++) {
		S = S + (pow(-1, i + 1) * (powf(radian(N, x), 2 * i - 1)) *
		1.0) / (facto(2 * i - 1)); //sen(x)=x-x^3/3!+x^5/5!
	}
	return(S);
}

double coseno(double N, float x) {
	double S = 1; 
	int i;
	if (x == 0) {
		cout << "No existe el coseno " << endl;
	} else {
		for (i = 1; i <= N; i++) {
			S = S - (pow(-1, i + 1) * (powf(radian(N, x), 2 * i)) * 1.0) / (facto(2 * i)); //sen(x)=x-x^3/3!+x^5/5!
		}
	}
	return(S);
}

double raiz2(double N, float x) {
	if (x <= 0) {
		cout << "Sin Soluciom Real " << endl;
		system("pause");
		exit(0);
	} else {
		double f1 = seno(N, x);
		double f2 = coseno(N, x);
		double f3 = (f1 - f2) / sqrt(x);
		return f3;
	}
}

int main() {
	double M; 
	float y;
	leeN(M);
	leex(y);
	cout << "El factorial de N = " << facto(M) << endl;
	cout << "En radian es " << radian(M, y) << endl;
	cout << "El seno de x = " << seno(M, y) << endl;
	cout << "El coseno de x = " << coseno(M, y) << endl;
	cout << "La Solucion es = " << raiz2(M, y) << endl;
	system("pause");
	return 0;
}



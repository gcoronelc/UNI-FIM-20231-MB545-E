#include <iostream>
using namespace std;

int main(){

	int a = 6;
	int b = 7;
	int c = ++a + b--;
	
	cout << "a: " << a << "\n";
	cout << "b: " << b << "\n";
	cout << "c: " << c << "\n";
}

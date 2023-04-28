#include <iostream>
using namespace std;

int main1001() {

	cout << "MAGIA 1001\n";
	bool isOk;
	for (int i = 30; i <= 90; i++) {
		isOk = (i % 3 == 0) ? ((i%5==0)?true:false) : false;
		if (isOk) {
			cout << i << "\t";
		}
	}
	cout << "\n";

	return 0;
}
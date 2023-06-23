#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main() {

	vector<string> words_array;
	string word;
	int ctad_palabras = 0, ctad_vocales[5] = {0, 0, 0, 0, 0,};

	ifstream fin;
	fin.open("archivo.TXT");

	if (!fin.is_open()) {
		cout << "NO SE PUDO ABRIR EL ARCHIVO\nDEBE TENER EL NOMBRE \"archivo.TXT\"" << endl;
		return -1;
	}

	while (getline(fin, word, ' ')) {
		words_array.push_back(word);
		ctad_palabras++;
		for (int i = 0; i < word.size(); i++) {
			switch (word[i]) {
			case 'a': case 'A': case 'á': case 'Á':
				ctad_vocales[0]++;
				break;
			case 'e': case 'E': case 'é': case 'É':
				ctad_vocales[1]++;
				break;
			case 'i': case 'I': case 'í': case 'Í':
				ctad_vocales[2]++;
				break;
			case 'o': case 'O': case 'ó': case 'Ó':
				ctad_vocales[3]++;
				break;
			case 'u': case 'U': case 'ú': case 'Ú': case 'ü': case 'Ü':
				ctad_vocales[4]++;
			}
		}
	}

	fin.close();

	ofstream fout;
	fout.open("REPORTE.TXT");

	fout << "==TEXTO ORIGINAL==" << endl;
	for (int i = 0; i < words_array.size(); i++) {
		fout << words_array[i] << " ";
	}
	fout << "\n\n==TEXTO INVERTIDO==" << endl;
	for (int i = words_array.size() -1; i >= 0; i--) {
		fout << words_array[i] << " ";
	}
	fout << "\n\n==ESTADÍSTICAS==" << endl;
	fout << "Cantidad de palabras: " << ctad_palabras << endl;
	fout << "Veces a: " << ctad_vocales[0];
	fout << "Veces e: " << ctad_vocales[1];
	fout << "Veces i: " << ctad_vocales[2];
	fout << "Veces o: " << ctad_vocales[3];
	fout << "Veces u: " << ctad_vocales[4];

	fout.close();

	return 0;
}
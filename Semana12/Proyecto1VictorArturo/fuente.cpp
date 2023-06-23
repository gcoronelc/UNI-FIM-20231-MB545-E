//Victor Arturo Ibañez Aliaga

#include <fstream>
#include <vector>
#include "Triangle.h"
#include <string>
#include <sstream>

using namespace std;

int main() {

	bool primera_linea = true;
	double lados[3];

	vector<Triangle> lista;
	string linea, dato;

	ifstream fin;
	fin.open("PROYECTO1-DATOS.TXT");

	while (getline(fin, linea, '\n')) {
		if (primera_linea) {
			primera_linea = false;
			continue;
		}
		istringstream iss(linea);
		for (int i = 0; getline(iss, dato, '|'); i++) {
			switch (i) {
			case 0:
				continue;
			case 1:
				lados[0] = stod(dato);
				break;
			case 2:
				lados[1] = stod(dato);
				break;
			case 3:
				lados[2] = stod(dato);
			}
		}
		lista.push_back(Triangle(lados[0], lados[1], lados[2]));
	}

	fin.close();

	int ctad_invalid = 0, ctad_eq = 0, ctad_is = 0, ctad_esc = 0;
	vector<string> string_tipos;

	for (int i = 0; i < lista.size(); i++) {
		switch(lista[i].tipo()) {
		case -1:
			string_tipos.push_back("");
			ctad_invalid++;
			break;
		case 0:
			string_tipos.push_back("Equilátero");
			ctad_eq++;
			break;
		case 1:
			string_tipos.push_back("Isóceles");
			ctad_is++;
			break;
		case 2:
			string_tipos.push_back("Escaleno");
			ctad_esc++;
		}
	}

	ofstream fout;
	fout.open("PROYECTO1-RESULTADO.TXT");

	fout << "ITEM|LADO1|LADO2|LADO3|ESTADO|TIPO|PERÍMETRO|AREA" << endl;

	for (int i = 0; i < lista.size(); i++) {
		fout << i + 1 << "|";
		fout << lista[i].get_a() << "|";
		fout << lista[i].get_b() << "|";
		fout << lista[i].get_c() << "|";
		if (lista[i].valid()) {
			fout << "VÁLIDO" << "|";
			fout << string_tipos[i] << "|";
			fout << lista[i].perim() << "|";
			fout << lista[i].area() << endl;
		}
		else {
			fout << "NO VÁLIDO|-|-|-" << endl;
		}
	}

	fout << "\nRESUMEN" << endl;
	fout << "Triángulos inválidos: " << ctad_invalid << endl;
	fout << "Triángulos equiláteros: " << ctad_eq << endl;
	fout << "Triángulos isóceles: " << ctad_is << endl;
	fout << "Triángulos escalenos: " << ctad_esc << endl;

	fout.close();

	return 0;

}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(const string& cadena, char caracter) {
    // Variables
    vector<string> arreglo;
    int posicion;
    string datos;
    string dato;
    // Proceso
    datos = cadena;
    while (datos.size() > 0) {
        posicion = datos.find(caracter);
        if (posicion > 0) {
            dato = datos.substr(0, posicion);
            datos.erase(0, posicion + 1);
        }
        else {
            dato = datos;
            datos = "";
        }
        arreglo.push_back(dato);
    }
    return arreglo;
}

int main() {
    // Variables
    string datos;
    char caracter = ',';
    int numero;
    char rpta;
    int suma;
    // Lectura
    datos = "";
    do {
        cout << "Ingrese numero entero: ";
        cin >> numero;
        datos = datos + to_string(numero);
        cout << "Ingresa otro numero (s/n): ";
        cin >> rpta;
        if (rpta == 'S' || rpta == 's')
            datos += caracter;
    } while (rpta == 'S' || rpta == 's');

    vector<string> arreglo = split(datos,caracter);
    cout << datos << "\n";
    cout << "Cantidad de elementos: " << arreglo.size() << "\n";
    suma = 0;
    for (int i = 0; i < arreglo.size();i++) {
        cout << arreglo[i] << endl;
        suma += stoi(arreglo[i]);
    }
    
    cout << "Suma: " << suma << "\n";
    system("pause");
    return 0;
}


/*
Desarrollar un programa para calcular el promedio de un estudiante.
Son 2 notas, y se aprueba con 14.
Condicion:
[18,20] Excelente
[14,18> Aprobado
[0,14> Desaprobado
*/

#include <iostream>

using namespace std;

int main()
{
    // Variables
    int nota1, nota2;
    float promedio;
    string condicion;
    // Lectura de datos
    cout << "LECTURA DE DATOS\n";
    cout << "======================================\n";
    cout << "Nota 1: "; cin >> nota1;
    cout << "Nota 2: "; cin >> nota2;
    // Proceso
    promedio = (nota1+nota2)/2.0;
    if( promedio>=18 ) condicion = "Excelente";
    else if(promedio>=14) condicion = "Aprobado";
    else condicion = "Desaprobado";
    // Reporte
    cout << "\n";
    cout << "REPORTE\n";
    cout << "======================================\n";
    cout << "Promedio: " << promedio << "\n";
    cout << "Condicion: " << condicion << "\n";
    return 0;
}

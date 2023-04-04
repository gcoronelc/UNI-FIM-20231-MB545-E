
/*
Desarrollar un programa para calcular el promedio de un estudiante.
Son 2 notas, y se aprueba con 14.
Condicion:
[18,20] Excelente
[14,18> Aprobado
[0,14> Desaprobado

Para calcular el promedio se tiene 3 sistemas:
1: Ambas notas tienen igual peso.
2: La nota 1 tiene peso 2.
3: La nota 2 tiene peso 2.
*/

#include <iostream>

using namespace std;

int main()
{
    // Variables
    int nota1, nota2, sistema;
    float promedio;
    string condicion;
    // Lectura de datos
    cout << "LECTURA DE DATOS\n";
    cout << "======================================\n";
    cout << "Nota 1: "; cin >> nota1;
    cout << "Nota 2: "; cin >> nota2;
    cout << "Sistema: "; cin >> sistema;
    // Proceso
    switch(sistema){
        case 1:
            promedio = (nota1+nota2)/2.0;
            break;
        case 2:
            promedio = (nota1*2+nota2)/3.0;
            break;
        case 3:
            promedio = (nota1 + nota2*2)/3.0;
            break;
    }
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
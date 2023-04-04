/*
Hacer un programa que genere 4 numeros aleatorios.
Luego debe reportar el mayor de ellos.
*/

#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;
 
int main()
{
    // Variables
    int num1, num2, num3, num4, mayor;
    // Generar numeros aleatorios
    srand(time(NULL));
    num1 = rand() % 11;
    num2 = rand() % 11;
    num3 = rand() % 11;
    num4 = rand() % 11;
    // Proceso
    mayor=num1; //valor por defecto
    mayor=(mayor<num2)?num2:mayor;
    mayor=(mayor<num3)?num3:mayor;
    mayor=(mayor<num4)?num4:mayor;
    // Reporte
   cout <<"Numero 1= "<< num1<<"\n"; 
   cout<< "Numero 2= "<<num2<<"\n";
   cout<<"Numero 3= "<<num3<<"\n";
   cout<<"Numero 4= "<<num4<<"\n";
    cout<<"El mayor es: "<<mayor<<"\n";
    return 0;
}
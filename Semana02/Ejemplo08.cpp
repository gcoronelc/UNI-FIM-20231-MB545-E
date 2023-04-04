/*
Generar numeros aleatorios del 10 al 20.

*/

#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;
 
int main()
{
    int num, c;
    srand(time(NULL));
    
    for(int i=1; i<=10;i++){
         num = 10 + rand() % 11;
        cout << num << " ";
    }
   
    
    return 0;
}
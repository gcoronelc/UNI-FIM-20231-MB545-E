/*
Generar un numero aleatorio menor que 10

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
         num = rand() % 10;
        cout << num << " ";
    }
   
    
    return 0;
}
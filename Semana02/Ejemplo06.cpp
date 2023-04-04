#include <stdlib.h>
#include <time.h>
#include<iostream>
using namespace std;
 
int main()
{
    int num, c;
    srand(time(NULL));
    
    num = rand(); // Genera numero aleatorio entero (int)
    cout << num << " ";
    
    return 0;
}
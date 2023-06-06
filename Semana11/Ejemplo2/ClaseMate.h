#include <iostream>
using namespace std;


class Mate{
	
	private:
		
		// Constructor por defecto privado
		// Para que no se puedan crear instancias
		Mate(){
		}
	
	public:
				
	static long factorial(int n){
		if(n==0 || n==1) return 1;
		else return n * factorial(n-1);
	}
	
	
};

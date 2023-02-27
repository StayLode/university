/* Scrivere un programma che dato un valore intero non negativo, restituisce il corrispondente numero di Fibonacci 
*/

#include <iostream>

using namespace std ;

int fib(int);

int main(){
    int numero;
    do {
      cout<<"Immetti un numero intero positivo:\n" ;
      cin>>numero ;
    }while(numero<0);
    cout<<"Il valore di Fibonacci per il numero "<<numero<<"e'"<<fib(numero)<<endl;
    return 0;
}

int fib(int n){
	if (n==0 || n==1)
		return n;
	return fib(n-1)+fib(n-2);
}

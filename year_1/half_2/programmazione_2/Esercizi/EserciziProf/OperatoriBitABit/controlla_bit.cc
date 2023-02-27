/*
  Scrivere un programma che legga da stdin due numeri naturali x ed n,
  e dica se il bit in posizione n è settato o meno nel numero x.
 */

#include <iostream>
using namespace std ;

main(){
	unsigned int x, n;
	cin>>x>>n ;
	
	if ((x & (1<<n)) != 0) 
		cout<<"Bit settato"<<endl ;
	else
		cout<<"Bit non settato"<<endl ;
}

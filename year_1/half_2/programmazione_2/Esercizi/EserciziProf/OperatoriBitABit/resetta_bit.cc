/*
  Scrivere un programma che legga da stdin due numeri naturali x ed n,
  e resetti il bit in posizione n nel numero x.
 */

#include <iostream>
using namespace std ;

main(){
	unsigned int x, n;
	cin>>x>>n ;
	
	x &= ~(1<<n) ;
	cout<<x<<endl ;
}

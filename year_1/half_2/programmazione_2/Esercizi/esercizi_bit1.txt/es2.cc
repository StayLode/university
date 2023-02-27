/*
Traccia: Scrivere un programma che legga da tastiera un numero naturale n e,
	 se n e' dispari, stampi 1, altrimenti stampi 0. 

Un possibile output su schermo e' il seguente:

Immettere il numero n: 7
Risultato: 1
*/

using namespace std;

#include <iostream>

int main(){
    int n, r;
    cout<<"Immettere il numero n: ";
    cin>>n;
    r = n & 1;
    cout<<"Risultato: "<<r<<endl;
}
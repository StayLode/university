/*
Traccia: Scrivere un programma che legge da tastiera due numeri
naturali n ed i, moltiplica il numero n per 2^i senza utilizzare
l'operatore moltiplicazione, e stampa il risultato sullo schermo.
Trascurare problemi di overflow.

Un possibile output su schermo e' il seguente:

Immettere il numero n: 3
Immettere il numero i: 4
3 * (2^4) = 48
*/
using namespace std;

#include <iostream>

int main(){
    int n, i;
    cout<<"Immettere il numero n: ";
    cin>>n;
    cout<<"Immettere il numero i: ";
    cin>>i;
    cout<<n<<" * "<<"2^"<<i<<" = ";
    n <<= i;
    cout<<n<<endl;
}
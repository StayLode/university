/*
Traccia: Scrivere un programma che legga da tastiera due numeri
naturali n ed i, effettui la divisione intera del numero n per 2^i
senza utilizzare l'operatore divisione, e stampi il risultato sullo
schermo.

Un possibile output su schermo e' il seguente:

Immettere il numero n: 12
Immettere il numero i: 2
12 / (2^2) = 3
*/

#include <iostream>

using namespace std;

int main(){
    int n, i;
    cout<<"Immettere il numero n: ";
    cin>>n;
    cout<<"Immettere il numero i: ";
    cin>>i;
    cout<<n<<" / "<<"2^"<<i<<" = ";
    n >>= i;
    cout<<n<<endl;
}
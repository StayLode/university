/*
Scrivere un programma che legga da stdin due
numeri naturali x ed n,e setti il bit in posizione n
nel numero x
*/

#include <iostream>

using namespace std;

int main(){
    int x, n;
    cout<<"Inserire il numero: ";
    cin>>x;
    cout<<"Inserire la posizione del bit da settare: ";
    cin>>n;

    x |= (1<<(n-1));

    cout<<x<<endl;

}
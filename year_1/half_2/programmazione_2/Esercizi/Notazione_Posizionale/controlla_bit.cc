/*
Scrivere un programma che effettui il controllo
sullo stato di un bit in un vettore
●Programma che legga da stdin due numeri
naturali x ed n, e dica se il bit in posizione n è
settato o meno nella rappresentazione del
numero x
*/

#include <iostream>

using namespace std;

int main(){
    int x, n;
    cout<<"Inserire il numero: ";
    cin>>x;
    cout<<"Inserire la posizione da controllare: ";
    cin>>n;

    if((x & (1<<(n-1))) != 0)
        cout<<"Bit settato"<<endl;
    else
        cout<<"Bit non settato"<<endl;

}
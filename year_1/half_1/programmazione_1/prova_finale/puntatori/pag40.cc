/*
* Scrivere un programma che utilizzi una funzione per
*   leggere da stdin un numero di valori di tipo int fornito a
* tempo di esecuzione del programma, ed inserisca tali
* valori in un array allocato dinamicamente dalla funzione
* stessa
*   La funzione deve restituire al main() l'indirizzo del primo
* elemento dell'array dinamico creato. Stampare poi
* l'array nel main()
*/
#include <iostream>

using namespace std ;

void creaVett(int * &p, int &dim){
    cout<<"Dimensione del vettore: ";
    cin>>dim;
    p=new int [dim];
    for(int i=0;i<dim;i++)
        cin>>p[i];
}

int main()
{
    int *a;
    int dim;
    creaVett(a, dim);
    cout<<"Vettore creato: ";
    for(int i=0;i<dim;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
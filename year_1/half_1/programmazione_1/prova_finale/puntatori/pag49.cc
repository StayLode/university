/* 
* Scrivere una funzione che prenda in ingresso un array di
* interi, ne crei un altro uguale, e ritorni (l'indirizzo del)
* secondo array mediante un parametro di uscita (un
* parametro quindi di tipo riferimento a puntatore).
* La funzione non legge niente da stdin e non scrive
* niente su stdout
*/
#include <iostream>

using namespace std ;

void copyVett(int *p1, int *&p2, int &dim){
    p2=new int[dim];
    for(int  i=0; i<dim; i++)
        p2[i]=p1[i];
}

int main()
{
    int dim;
    cout<<"Dimensione del vettore: ";
    cin>>dim;
    int *a=new int[dim]{2,10,11,23,1};
    int *b;
    copyVett(a, b, dim);
    cout<<"Vettore Copiato: ";
    for(int i=0;i<dim;i++)
        cout<<b[i]<<" ";
    cout<<endl;
}
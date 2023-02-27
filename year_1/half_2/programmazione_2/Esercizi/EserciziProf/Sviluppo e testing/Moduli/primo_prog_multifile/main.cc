#include <iostream>

using namespace std ;

int a ;      // definizione di una variabile con collegamento esterno
void fun() ; // dichiarazione della funzione globale esterna

int main()
{
    cout<<"Inserisci il valore della variabile: " ;
    cin>>a ;
    fun() ;
    return 0 ;
}

/*
    Scrivere, mediante una funzione ricorsiva, un programma che chieda 
    all'utente di inserire un numero naturale n e stampi tutti i numeri da n
    a 1.
    Un possibile output e' il seguente:

    Valore massimo della sequenza di numeri da stampare? 5
    5
    4
    3
    2
    1
*/
    
#include <iostream>

using namespace std ;

void stampa(int n)
{
    if (n == 0)
        return ;
    cout<<n<<endl ;
    stampa(n-1) ;
}

int main ()
{
    int max ;
    
    cout<<"Valore massimo della sequenza di numeri da stampare? " ;
    cin>>max ;
    stampa(max) ;

    return 0 ;
}

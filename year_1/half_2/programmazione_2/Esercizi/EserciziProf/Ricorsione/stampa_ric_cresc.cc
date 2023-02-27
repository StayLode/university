/*
    Scrivere, mediante una funzione ricorsiva, un programma che chieda 
    all'utente di inserire un numero naturale n e stampi tutti i numeri da 1
    a n.
    Non utilizzare l'operatore somma o incremento.
    Un possibile output e' il seguente:

    Valore massimo della sequenza di numeri da stampare? 5
    1
    2
    3
    4
    5
*/
    
#include <iostream>

using namespace std ;

void stampa(int n)
{
    if (n == 0)
        return ;
    stampa(n-1) ;
    cout<<n<<endl ;
}

int main ()
{
    int max ;
    
    cout<<"Valore massimo della sequenza di numeri da stampare? " ;
    cin>>max ;
    stampa(max) ;

    return 0 ;
}

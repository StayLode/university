/*
Scrivere un programma che legga in ingresso due numeri, uno reale ed
uno intero e stampi il risultato dell'elevamento a potenza del numero
reale per il numero intero. Consideriamo solo il caso di esponente
positivo o nullo.  Realizzare sia una versione iterativa che una
versione ricorsiva dell'algoritmo.

Trascuriamo problemi di overflow.

E' presentata anche una versione iterativa della funzione potenza
*/

#include <iostream>

using namespace std ;


double pot_ricorsiva(double a, int n)
{
    if (n == 0)
	return 1 ;
    return a * pot_ricorsiva(a, n - 1) ;
}

double pot_iterativa(double a, int n)
{
     double b = 1;
     int i ;

     for (i = 0 ; i < n ; i++)
     	b *= a ;
     return b ;
}

int main()
{
    double a ;
    int n ;

    cout<<"Inserisci il numero da elevare: " ;
    cin>>a ;
    cout<<"Inserisci l'esponente: " ;
    cin>>n ;
    // utilizzo la versione ricorsiva della funzione
    cout<<"Il valore di "<<a<<"^"<<n<<" e' "<<pot_ricorsiva(a, n)<<endl ;

    return 0 ;
}

/*
  Scrivere un programma che stampi il contenuto di un vettore di
  interi definito ed inizializzato a tempo di scrittura del programma
  stesso e che contiene almeno un elemento di valore -1. In
  particolare lo stesso vettore va stampato due volte, utilizzando
  ciascuna volta una funzione diversa. Le due funzioni di stampa
  devono avere un solo parametro formale, non devono utilizzare
  variabili globali, e devono stampare gli elementi del vettore
  fermandosi non appena incontrano l'elemento di valore -1 (senza
  stamparlo).

  La prima funzione non deve utilizzare l'operazione di selezione con
  indice, mentre la seconda non deve utilizzare né l'operazione di
  selezione con indice né alcuna variabile locale.

 */


#include <iostream>
using namespace std ;

void stampa_1( int v[])
{
	for (int i = 0 ; *(v + i) != -1 ; i++)
		cout<<*(v+i)<<endl ;
}

void stampa_2( int v[])
{
	for (; *v != -1 ; v++)
		cout<<*v<<endl ;
}

int main()
{
	const int N = 5 ;
	int a[N] = {1, 4, 3, -1, 7} ;

	cout<<"Stampa usando somma di un intero ad un indirizzo:"<<endl ;
	stampa_1(a) ;
	cout<<endl<<"Stampa usando incremento puntatore:"<<endl ;
	stampa_2(a) ;
	return 0 ;
}


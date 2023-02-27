/*
Scrivere un programma che stampi il fattoriale di un numero intero
non negativo letto dallo stdin. Implementare il calcolo (e non la stampa)
del fattoriale mediante una funzione ricorsiva. Implementare la lettura del
valore e la stampa del fattoriale all'interno del main.
Trascurare problemi di overflow.
*/

#include <iostream>

using namespace std ;

int fattoriale (int);

int main ()
{
  int numero;
  do {
    cout<<"Immetti un numero intero positivo:\n" ;
    cin>>numero ;
  }while(numero<0);
  cout<<numero<<"! == "<<fattoriale(numero)<<endl;
  return 0;
}

/*
 * Legge in ingresso un numero intero n, e ritorna il valore n!
 */
int fattoriale (int n)
{
    if (n == 0)
	return 1 ;
    return n * fattoriale(n - 1) ;
}

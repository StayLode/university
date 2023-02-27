/*
    Dato un numero intero n > 0, definiamo residuo del numero n il
    numero che si ottiene dal seguente algoritmo iterativo.
    Finche' il resto della divisione intera di n per 7 
    e' uguale a 0, oppure e' maggiore di 4, si continua a dividere il 
    numero n per 7.
    Il seguente programma legge n da stdin e calcola il residuo.

    Esempi di input/output:
    . Immettendo 49 da come residuo 1
    . Immettendo 7321 da come residuo 1045
    . Immettendo 245 ...

    Trovare l'errore!
*/

#include <iostream>

using namespace std ;

int main()
{
    int n ;
    
    do {
	cout<<"Inserire il numero di cui calcolare il residuo: " ;
	cin>>n ;
    } while (n <= 0) ;
    
    while ( n % 7 == 0 || n % 7 > 4 )
            n /= 7 ;
    
    cout<<"Residuo: "<<n<<"\n" ;
        
    return 0 ;
}

/*
  Il seguente programma deve stampare a video la tabella dei codici
  ASCII a partire dall'ultimo carattere in righe di 8 caratteri.  
  Per ogni carattere il programma dovrebbe
  stampare il carattere stesso ed il codice ASCII (in base 10).

  Compilare, eseguire, e nel caso non funzionasse, trovare l'errore.
*/

#include <iostream>

using namespace std ;

int main()
{
    unsigned int i = 127 ;
    while ( i >= 0 ) {
	if ( i % 8 == 0 )
	    cout<<'\n' ;
	cout<<'\t'<<i<<' '<<static_cast<char>(i) ;
	i-- ;
    }
    cout<<endl ;
    return 0 ;	
}

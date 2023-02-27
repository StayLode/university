#include <iostream>

using namespace std ;

void stampa_mondo()
{
    cout<<"mondo"<<endl ;
}

int main()
{
    cout<<"Ciao,"<<flush ; // l'operatore di uscita � bufferizzato,
			   // per cui, siccome non si mette l'endl, si
			   // usa il flush per assicurarsi che la
			   // stringa sia inviata subito sullo stdout
    stampa_mondo() ;
    return 0 ;
}

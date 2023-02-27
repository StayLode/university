/*
 * Programma di esempio di compilazione condizionale.
 */
#include <iostream>

using namespace std ;

#define X

int main()
{
#ifdef X
    cout<<"Macro X definita"<<endl ;
#else
    cout<<"Macro X non definita"<<endl ;
    cout<<"Se X non è definita vi sarà un errore di sintassi perchè manca il ; "<<endl
    cout<<"Altrimenti nessun errore,perché questa parte di codice non è "
	<<"compilata affatto" <<endl ;
#endif
    return 0 ;
}

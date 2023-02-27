/*
Bisogna gestire lo stato di illuminazione di una strada in termini di lampioni funzionanti. 
La lista dei lampioni funzionanti è mantenuta attraverso una configurazione di bit (supponiamo 8 bit).
Ad ogni lampione è associato un bit della configurazione, che ne indica lo stato: 1 se il lampione è funzionante, 0 se il lampione è guasto.
 
Le funzioni previste sono:
1.aggiornamento dello stato di un lampione, che puo' guastarsi o essere riparato
2.stampa dei lampioni funzionanti
3.controllo se i lampioni possono funzionare in modalità risparmio energetico, 
ovvero quelli di indice pari accesi e quelli di indice dispari spenti. Nota bene: per essere verificata, tutti i lampioni di indice pari
devono essere accesi e tutti quelli di indice pari spenti.

Utilizzare una funzione ausiliaria per guastare/riparare lampioni

All'inizio tutti i lampioni gestiti dal programma sono funzionanti. 
Il programma deve fornire il seguente menù:


        Gestione lampioni

        Comandi disponibili:
        G Segnalare guasto ad un lampione
        R Segnalare riparazione di un lampione
        L Stampa lista lampioni funzionanti
        T Termina

-----------------

Esempi di esecuzione del programma:


        Gestione lampioni

        Comandi disponibili:
        G Segnalare guasto ad un lampione
        R Segnalare riparazione di un lampione
        L Stampa lista lampioni funzionanti
        T Termina
        L
        I lampioni funzionanti sono i seguenti: 0 1 2 3 4 5 6 7


        Gestione lampioni

        Comandi disponibili:
        G Segnalare guasto ad un lampione
        R Segnalare riparazione di un lampione
        L Stampa lista lampioni funzionanti
        T Termina
        G
        Quale lampione si e' guastato ? 3


        Gestione lampioni

        Comandi disponibili:
        G Segnalare guasto ad un lampione
        R Segnalare riparazione di un lampione
        L Stampa lista lampioni funzionanti
        T Termina
        L
        I lampioni funzionanti sono i seguenti: 0 1 2 4 5 6 7
*/

#include <iostream>

using namespace std ;

/*
 * Setta lo stato del lampione prescelto 
 * funziona == true  => lampione funzionante 
 * funziona == false => lampione guasto 
 */
void aggiorna(unsigned short int &strada, int lampione, bool funziona)
{
    if (funziona)
	    strada |= 1<<lampione ;
    else
	    strada &= ~(1<<lampione) ;
}

bool risparmio_energetico(unsigned short int strada, int num_lampioni) {
    unsigned int check = 1;
    bool risparmio = true;
   /* for (int i = 0; i < (num_lampioni/2) ; i++) {
        risparmio &= ((strada & check) == check);
        check = check << 1;
        risparmio &= ((strada | check) != strada);
        check = check << 1;
    }
    */
    //return risparmio;

    for (int i = 0; i < (num_lampioni/2) ; i++) {
        if (!((strada & check) == check))
            return false;
        check = check << 1;
        if (!((strada | check) != strada))
            return false;
        check = check << 1;
    }
}

int main()
{
    unsigned short int strada = ~0 ; /* All'inizio tutti i lampioni funzionano */
    int num_lampioni = sizeof (strada) * 8 ; 
    for (;;) { /* menu */
	    char scelta ;

        cout << "Gestione lampioni" << endl << endl ;
        cout << "Comandi disponibili:" << endl ;
        cout << "\tG Segnalare guasto ad un lampione" << endl ;
        cout << "\tR Segnalare riparazione di un lampione" << endl ;
        cout << "\tL Stampa lista lampioni funzionanti" << endl ;
        cout << "\tK Controllo risparmio energetico" << endl;
        cout << "\tT Termina" << endl ;
        cin >> scelta ;

        switch(scelta) {
            int lampione ;

            case 'G':
            case 'g':
                cout << "\tQuale lampione si e' guastato ? " ;
                cin >> lampione ;
                aggiorna(strada, lampione, false) ;
                break ;
            case 'R':
            case 'r':
                cout << "\tQuale lampione e' stato riparato ? " ;
                cin >> lampione ;
                aggiorna(strada, lampione, true) ;
                break ;
            case 'L':
            case 'l':
                cout << "\tI lampioni funzionanti sono i seguenti: " ;
                for (int i = 0 ; i < num_lampioni ; i++)
                    if (strada & (1 << i))
                    cout << i <<" " ;
                cout << endl;
                break ;
            case 'K':
            case 'k':
                cout << risparmio_energetico(strada, num_lampioni) << endl;
                break;
            case 'T':
            case 't':
                return 0 ;
            default:
                cout << "\tScelta non valida" << endl ;
        } // Fine switch
    } 
}
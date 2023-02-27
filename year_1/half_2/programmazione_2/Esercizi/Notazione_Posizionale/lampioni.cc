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

using namespace std;

void guasta(int num, int *l){ *l &= ~(1<<(num-1));}

void ripara(int num, int *l){ *l |= (1<<(num-1));}

bool flamp(int n, int *l, void(*pfun)(int, int*)){
    if(n <= 0  || n >= 9)
        return false;
    pfun(n, l);
    return true;
}

void stampalamp(const int l){
    cout<<"I lampioni funzionanti sono: ";
    for(int i = 0; i < 8; i++){
        if ((l & 1<<i) != 0)
            cout<<i+1<<" ";
    }
    cout<<endl;
}



int main(){
    int lampioni = 255, pos;
    char op;
    do{
        cout<<"G Segnalare guasto ad un lampione \n"
        <<"R Segnalare riparazione di un lampione \n"
        <<"L Stampa lista lampioni funzionanti \n"
        <<"K Controllo risparmio energetico \n"
        <<"T Termina\n";  
        cin>>op;
        switch(op){
            case 'G':
                cout<<"Inserire lampione da guastare: ";
                cin>>pos;
                flamp(pos, &lampioni, guasta);
                break;
            case 'R':
                cout<<"Inserire lampione da riparare: ";
                cin>>pos;
                flamp(pos, &lampioni, ripara);
                break;
            case 'L':
                stampalamp(lampioni);
                break;
            default:
                break;
        }
    }while(op != 'T');

}
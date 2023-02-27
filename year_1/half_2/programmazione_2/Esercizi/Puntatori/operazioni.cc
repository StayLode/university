/*
Scrivere un programma che:
    –Richieda se effettuare un'operazione di
    addizione, sottrazione, moltiplicazione o divisione
    tra due interi
    –A seconda dell'operazione scelta, invochi una
    funzione che fornisca il risultato corretto
    –La selezione della funzione avvenga senza
    costrutti if, switch, etc.
*/

#include <iostream>

using namespace std;
//per creare un vettore le funzioni devono essere compatibili
//devono avere gli stessi parametri di ritorno e di ingresso
int addizione(int x, int y){ return x+y; };
int sottrazione(int x, int y){ return x-y; };
int moltiplicazione(int x, int y){ return x*y; };
int divisione(int x, int y){ return x/y; };

int main(){
    int (* puntaop[4])(int, int) = {addizione, sottrazione, moltiplicazione, divisione};
    int x, y, op;
    cout<<"Inserire i due interi: ";
    cin>>x>>y;
    cout<<" 0 - Addizione \n 1 - Sottrazione \n 2 - Moltiplicazione \n 3 - Divione \n";
    cout<<"Inserire scelta "<<endl;
    cin>>op;
    cout<<puntaop[op](x,y)<<endl;
}
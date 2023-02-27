/*
Scrivere un programma in cui:
    -sia definita (a tempo di scrittura del programma stesso)
    una lista formata da due elementi, contenenti i valori 3
    e 7
    -si stampi il contenuto della lista mediante la funzione
    stampalista
*/

using namespace std;

#include <iostream>

struct elem{
    int inf;
    elem *pun;
};

typedef elem* lista;

int head(lista l){return l->inf;}
lista tail(lista l){return l->pun;}

void stampalista(lista l){
    while(l != NULL){
        cout << head(l) << " ";
        l = tail(l);
    }
    cout<<endl;
}

int main(){
    lista testa = new elem;

    testa->inf = 3;
    
    lista p = new elem; //creo un nuovo elemento
    p->inf = 7;
    p->pun = NULL;

    testa->pun = p; //aggancio l'elemento
    stampalista(testa);
}
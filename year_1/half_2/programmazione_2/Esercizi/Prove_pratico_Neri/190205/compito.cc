#include <iostream>
#include <cstring>
#include "tipo.h"
#include "liste.h"
using namespace std;

void pesca(lista& l){
    tipo_inf c;
    cout << "Inserisci valore e seme: ";
    cin >> c.valore >> c.seme;
    
    l = ord_insert_elem(l, new_elem(c));
}

void stampa(lista p){
	while (p != NULL){
		cout << head(p).valore << head(p).seme << " ";
		p = tail(p);
	}
}

carta* scala(lista l, int& lunghezza){
    bool flag = false;
    lista start_tmp = NULL;
    lista start = NULL;
    carta* c = NULL;


    while(tail(l) != NULL && !flag){
        if(head(l).seme == head(tail(l)).seme && head(tail(l)).valore == head(l).valore+1){
            lunghezza++;
            if(lunghezza >= 2){
                start = tail(l);
                flag = true;
                start_tmp = start;
            }
        }
        else if(lunghezza < 2 && !flag){
            lunghezza = 0;
        }
		l = tail(l);
	}
    
    while(tail(start_tmp) != NULL && flag){
        if(head(start).seme == head(tail(start_tmp)).seme && head(tail(start_tmp)).valore == head(start).valore+1){
            lunghezza ++;
            start = tail(start);
        }
        start_tmp = tail(start_tmp);
    }
    
    if(flag){
        for(int i=0; i<lunghezza; i++)
            start = prev(start);
        c = &start->inf;
    }
    return c;
}

int cala(lista& l){
    int lunghezza = 0;
    carta* c = NULL;
    c = scala(l, lunghezza);
    lista start = NULL;
    lista l_temp = l;
    int punteggio = 0;

    //cout << "DEBUG: " << endl;
    //stampa(l);

    
    if(c != NULL){
            start = ord_search(l, *c);

        for(int i = 0; i<lunghezza+1; i++){
            punteggio += start->inf.valore;
            if(l==start)
		        l=start->pun;
		    else
			    (start->prev)->pun = start->pun;
		    if(start->pun!=NULL)
			    (start->pun)->prev=start->prev;

            start = tail(start);
        }
        return punteggio;
    }
    else
        return 0;
}

int main(){
    int num;
    lista l1 = NULL;
    lista l2 = NULL;
    int lun1, lun2;
    int pun1, pun2;
    bool flag = false;
    
    //! punto 1
    cout << "Inserisci quante carte pescare (Giocatore 1): ";
    cin >> num;
    for(int i=0; i<num; i++)
        pesca(l1);
    
    cout << "Inserisci quante carte pescare (Giocatore 2): ";
    cin >> num;
    for(int i=0; i<num; i++)
        pesca(l2);
    
    cout << "Giocatore 1: ";
    stampa(l1);
    cout << endl << "Giocatore 2: ";
    stampa(l2);
    cout << endl;

    //! punto 2
    int lunghezza = 0;
    carta* c = NULL;

    c = scala(l1, lunghezza);
    lun1 = lunghezza;
    if(c != NULL){
        cout << c->valore << c->seme << " ";
        for(int i=1; i<lunghezza+1; i++)
            cout << c->valore+i << c->seme << " ";
    }
    else
        cout << c;

    cout << endl;

    lunghezza = 0;

    c = scala(l2, lunghezza);
    lun2 = lunghezza;
    if(c != NULL){
        cout << c->valore << c->seme << " ";
        for(int i=1; i<lunghezza+1; i++)
            cout << c->valore+i << c->seme << " ";
    }
    else
        cout << c;

    
    //! punto 2.a
    cout << "\n\nTURNO UNO: " << endl;
    pesca(l1);
    pun1 = cala(l1);
    cout << "PUNTEGGIO: " << pun1 << "\t";
    stampa(l1);

    cout << endl;


    pesca(l2);
    pun2 = cala(l2);
    cout << "PUNTEGGIO: " << pun2 << "\t";
    stampa(l2);

    cout << endl;

    if((l1 == NULL || l2 == NULL)){
        flag = true;
        if(pun1 > pun2)
            cout << "Fine gioco: Vince giocatore 1\n";
        else
            cout << "Fine gioco: Vince giocatore 2\n";
    }
    
    if(!flag){
        cout << "\n\nTURNO DUE: " << endl;
        pesca(l1);
        pun1 += cala(l1);
        cout << "PUNTEGGIO: " << pun1 << "\t";
        stampa(l1);

        cout << endl;
        
        pesca(l2);
        pun2 += cala(l2);
        cout << "PUNTEGGIO: " << pun2 << "\t";
        stampa(l2);

        cout << endl;

        if((l1 == NULL || l2 == NULL)){
            if(pun1 > pun2)
                cout << "Fine gioco: Vince giocatore 1\n";
            else
                cout << "Fine gioco: Vince giocatore 2\n";
        }
    }
    
    return 0;
}
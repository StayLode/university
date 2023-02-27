/*
Il programma consente all'utente di accedere ad una lista di URL. Ogni URL ha al più 50 caratteri.

Il programma presenta un menù all'utente che può
- creare una lista di n URL attraverso la funzione insert_elem()
- cancellare un URL dato dalla lista attraverso la funzione delete_elem()
- stampare la lista attraverso head() e tail()
- cercare un URL nella lista e quindi consentire all'utente di muoversi a piacere avanti (F-forward) e
indietro (B-backward) nella lista a partire dalla posizione del sito cercato fino a quando non digita
S-stop, usando la funzione search()
 
 E' richiesto di completare le primitive che agiscono sui puntatori e la funzione naviga.
 *
 */

#include <iostream>
#include <cstring>

using namespace std ;

struct elem
{
       char inf[51] ;
       elem* pun ;
       elem* prev;
} ;

typedef elem* lista ;

// primitive

char* head(lista p){return p->inf;}

lista tail(lista p){return p->pun;}
lista prev(lista p){return p->prev;}

lista insert_elem(lista l, elem* e){
	/*...*/
}

lista delete_elem(lista l, elem* e){

	/*...*/
}

elem* search(lista l, char* v){
	while(l!=NULL)
		if(strcmp(head(l),v)==0)
			return l;
		else
			l=tail(l);
	return NULL;}

// funzioni

void stampalista(lista p)
{
	cout<<"[";
	while (p != NULL) {
		cout<<head(p)<<" " ; // stampa valore
		cout<<"(p: "<<p<< " succ:"<<p->pun<<" prev:"<<p->prev<<")";
		p = tail(p);     // spostamento sul
			                  // prossimo elemento
	}
	cout<<"]"<<endl;
}


lista crealista(int n)
{
      lista testa = NULL ;
      for (int i = 1 ; i <= n ; i++) {
          elem* p = new elem ;
          cout<<"URL "<<i<<": " ;
          cin>>p->inf;
          p->pun=p->prev=NULL;
          testa=insert_elem(testa,p);
      }
      return testa ;
}

lista cancella(lista l, char* v){
	elem* e;
	while((e=search(l,v))!=NULL){
		cout<<"Cancello un elemento con valore "<<v<<endl;
		l=delete_elem(l,e);}
	cout<<"Fine cancellazione!!"<<endl;
	return l;
}

void naviga(elem* e){
	char scelta;
	cout<< "Trovato!!";
	do{
		cout<< "Cosa vuoi fare (B per backward,F per forward, S per stop)"<<endl;
		cin>>scelta;
        /*.......*/
    }		while(scelta!='S');
}
int main()
{
    int n;
    char v[51];
    int scelta;
    lista testa=NULL;
    elem* ris;

    do{
    		cout<< "Cosa vuoi fare?"<<endl;
    		cout<< "1: creare una lista"<<endl;
    		cout<<"2:cancellare valori dalla lista"<<endl;
    		cout<<"3: stampare la lista"<<endl;
    		cout<<"4:cercare valori nella lista"<<endl;
    		cout<<"5:esci"<<endl;
    		cin>>scelta;
    		switch(scelta){
    		case 1: cout << "Inserire il numero di elementi da inserire nella lista" << endl;
    		cin >> n;
    		testa = crealista(n);
    		break;
    		case 2: cout<<"Inserire il valore da cancellare:"<<endl;
    		cin>>v;
    		testa=cancella(testa,v);
    		break;
    		case 3: stampalista(testa);
    		break;


    		cin>>v;
        ris=search(testa,v);
    		if(ris!=NULL)
    			naviga(ris);

    		else
    			cout<<"Valore non presente"<<endl;
    		break;
    		case 5: cout<<"Ciao, ciao!!"<<endl;}
    		}while(scelta!=5);
    return 0;
}

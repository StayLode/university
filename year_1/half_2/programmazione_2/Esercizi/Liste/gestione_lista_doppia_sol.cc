/*
  Scrivere un programma per la gestione di liste doppie.
  Il programma presenta un menù all'utente che può
  - creare una lista di n valori
  - cancellare tutti tutti gli elementi contenente un valore dato dalla lista
  - stampare la lista
  - cercare valori nella lista con search().
*/

#include <iostream>
#include <cstring>

using namespace std ;

struct elem
{
       char* inf[51] ;
       elem* pun ;
       elem* prev;
} ;

typedef elem* lista ;

// primitive

char* head(lista p){return p->inf;}

lista tail(lista p){return p->pun;}
lista prev(lista p){return p->prev;}

lista insert_elem(lista l, elem* e){
	e->pun=l;
	if(l!=NULL)
		l->prev=e;
	e->prev=NULL;
	return e;
}

elem* new_elem(char* newinf){
	elem* p = new elem ;
	strcpy(p->inf, newinf);
	p->pun=p->prev=NULL;
	return p;
}

lista delete_elem(lista l, elem* e){

		if(l==e)
			l=e->pun; // e è la testa della lista
		else // e non è la testa della lista
			(e->prev)->pun = e->pun;
		if(e->pun!=NULL)
			(e->pun)->prev=e->prev;
		delete e;
		return l;
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
		//cout<<"(p: "<<p<< " succ:"<<p->pun<<" prev:"<<p->prev<<")";
		p = tail(p);     // spostamento sul
			                  // prossimo elemento
	}
	cout<<"]"<<endl;
}

lista crealista(int n)
{
      lista testa = NULL ;
	  char inf[51];
      for (int i = 1 ; i <= n ; i++) {
          cout<<"URL "<<i<<": " ;
		  cin>>inf;
          testa=insert_elem(testa,new_elem(inf));
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
	    if(scelta=='F' && tail(e)!=NULL){
	    			cout<<head(tail(e))<<endl;
	    			e=tail(e);}
	    else
	    		if(scelta=='B' && prev(e) !=NULL){
	    			cout<<head(prev(e))<<endl;
	    			e=prev(e);}
	    		else cout<<"Elemento non esistente!!"<<endl;}		while(scelta!='S');
}

bool palindroma(lista l){
	lista l1 = l;

	while(tail(l1) != NULL)
		l1 = tail(l1);
	
	while(prev(l1) != NULL)
		if(strcmp(head(l1),head(l)) != 0) //! compare(head(l1), head(l))
			return false;
		else{
			l1 = prev(l1);
			l = tail(l);
		}
	
	return true;
}

int picchi(lista l){
	int p = 0;
	
	if(l == NULL)
		return p;

	if( (prev(l) == NULL && strcmp(head(l), head(tail(l))) > 0) || (tail(l) == NULL && strcmp(head(l),head(prev(l))) > 0) || (strcmp(head(l),head(prev(l))) > 0 && strcmp(head(l), head(tail(l))) > 0 ))
		p++;
		
	return p + picchi(tail(l));
			
}

int max(elem* e){
	lista dietro; 
	lista avanti;
	int counter = 0;

	while(tail(e) != NULL || prev(e) != NULL){
		if(prev(e) != NULL){
			dietro = prev(e);
			if(head(dietro) > head(e))
				counter++;
		}
		if(tail(e) != NULL){
			avanti = tail(e);
			if(head(avanti) > head(e))
				counter++;
		}
	}

	return counter;


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
    		cout<<"2: cancellare valori dalla lista"<<endl;
    		cout<<"3: stampare la lista"<<endl;
    		cout<<"4: cercare valori nella lista"<<endl;
			cout<<"5: palindroma? "<<endl;
			cout<<"6: numero picchi "<<endl;
    		cout<<"7: esci"<<endl;
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
    		case 4: cout << "Valore da cercare"<<endl;
    		cin>>v;
   			ris=search(testa,v);
    		if(ris!=NULL)
    			naviga(ris);
    		else
    			cout<<"Valore non presente"<<endl;
    		break;
			case 5:
			if(palindroma(testa))
				cout<<"Lista palindroma"<<endl;
			else
				cout<<"Lista NON palindroma"<<endl;
			case 6:
			cout<<picchi(testa);
			break;
    		case 7: cout<<"Ciao, ciao!!"<<endl;}
    		}while(scelta!=7);
    return 0;
}

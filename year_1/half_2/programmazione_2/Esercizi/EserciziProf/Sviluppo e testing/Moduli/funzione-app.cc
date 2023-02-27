/*
  Scrivere un programma per la gestione di liste doppie.
  Il programma presenta un menù all'utente che può
  - creare una lista di n valori (volendo ordinata)
  - cancellare tutti tutti gli elementi contenente un valore dato dalla lista
  - stampare la lista
  - cercare valori nella lista
  Se la lista è ordinata la ricerca deve richiamare ord_search() altrimenti search().
*/

#include <iostream>
#include <cstring>

using namespace std ;

/*******************************/
/* HEADER MODULO "liste-tipo" */
/*******************************/

struct elem
{
       char inf[51] ;
       elem* pun ;
       elem* prev;
} ;

typedef elem* lista ;

int compare(char*,char*);
char* head(lista);
elem* ord_search(lista, char*);
elem* new_elem(char*);
elem* search(lista, char*);

/*******************************/
/* HEADER MODULO "liste" */
/*******************************/
	
lista tail(lista);
lista prev(lista);
lista insert_elem(lista, elem*);
lista delete_elem(lista, elem*);
lista ord_insert_elem(lista, elem*);

/**********************************************/
/* HEADER MODULO "funzioni dell'applicazione" */
/**********************************************/
void stampalista(lista);
lista crealista(int, bool);
lista cancella(lista, char*);
void naviga(elem*);


/*******************************/
/* DEFINIZIONE MODULO "liste-tipo" */
/*******************************/

int compare(char* s1,char* s2){
	return strcmp(s1,s2);
}

char* head(lista p){return p->inf;}

elem* search(lista l, char* v){
	while(l!=NULL)
		if(strcmp(head(l),v)==0)
			return l;
		else
			l=tail(l);
	return NULL;}
	
elem* ord_search(lista l, char* v){
		while(l!=NULL && strcmp(head(l),v)<=0)
			if(strcmp(head(l),v)==0)
				return l;
			else
				l=tail(l);
		return NULL;}
	
elem* new_elem(char* inf){
	    elem* p = new elem ;
	    strcpy(p->inf,inf);
	    p->pun=p->prev=NULL;
		return p;
	
	}



/*******************************/
/* DEFINIZIONE MODULO "liste" */
/*******************************/

lista tail(lista p){return p->pun;}
lista prev(lista p){return p->prev;}

lista insert_elem(lista l, elem* e){
	e->pun=l;
	if(l!=NULL)
		l->prev=e;
	e->prev=NULL;
	return e;
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


lista ord_insert_elem(lista l, elem* e){
	if(l==NULL || compare(e->inf,head(l))<0)
		return insert_elem(l,e);
	else{
		lista l1=l;
		while (tail(l1)!=NULL && compare(head(tail(l1)),e->inf)<0)
			 l1=tail(l1);
		e->pun = l1->pun;
		if(l1->pun != NULL)
			l1->pun->prev=e;
		l1->pun = e;
		e->prev = l1;
		return l;}
}






/***************************************************/
/* DEFINIZIONE MODULO "funzioni dell'applicazione" */
/***************************************************/

void stampalista(lista p)
{
	cout<<"[";
	while (p != NULL) {
		cout<<head(p)<<" " ; // stampa valore
		p = tail(p);     // spostamento sul
			                  // prossimo elemento
	}
	cout<<"]"<<endl;
}


lista crealista(int n, bool ord)
{
	char url[80];
      lista testa = NULL ;
      for (int i = 1 ; i <= n ; i++) {
          cout<<"URL "<<i<<": " ;
          cin>>url;
		  elem* p = new_elem(url);
          if(ord)
        	  	  testa=ord_insert_elem(testa,p);
          else
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
	    if(scelta=='F' && tail(e)!=NULL){
	    			cout<<head(tail(e))<<endl;
	    			e=tail(e);}
	    else
	    		if(scelta=='B' && prev(e) !=NULL){
	    			cout<<head(prev(e))<<endl;
	    			e=prev(e);}
	    		else cout<<"Elemento non esistente!!"<<endl;}		while(scelta!='S');
}

/**********************************************/
/* DEFINIZIONE MODULO "MAIN"                  */
/**********************************************/
int main()
{
    int n;
    char v[51];
    int scelta;
    bool ordinata;
    lista testa=NULL;
    elem* ris;

    do{
    		cout<< "Cosa vuoi fare?"<<endl;
    		cout<< "1: creare una lista (ordinata)"<<endl;
    		cout<<"2:cancellare valori dalla lista"<<endl;
    		cout<<"3: stampare la lista"<<endl;
    		cout<<"4:cercare valori nella lista"<<endl;
    		cout<<"5:esci"<<endl;
    		cin>>scelta;
    		switch(scelta){
    		case 1: cout << "Come vuoi creare la lista (1:ordinata,0:non ordinata)?"<<endl;
    		cin>>ordinata;
    		cout << "Inserire il numero di elementi da inserire nella lista" << endl;
    		cin >> n;
    		testa = crealista(n,ordinata);
    		break;
    		case 2: cout<<"Inserire il valore da cancellare:"<<endl;
    		cin>>v;
    		testa=cancella(testa,v);
    		break;
    		case 3: stampalista(testa);
    		break;
    		case 4: cout << "Valore da cercare"<<endl;
    		cin>>v;
    		if(ordinata)
    			ris=ord_search(testa,v);
    		else
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

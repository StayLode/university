
#include <iostream>
#include <cstring>

using namespace std ;

#include "liste-tipo.h"
#include "liste.h"
#include "fun-app.h"

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


lista crealista(int n)
{
	char url[80];
      lista testa = NULL ;
      for (int i = 1 ; i <= n ; i++) {
          cout<<"URL "<<i<<": " ;
          cin>>url;
		  elem* p = new_elem(url);
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
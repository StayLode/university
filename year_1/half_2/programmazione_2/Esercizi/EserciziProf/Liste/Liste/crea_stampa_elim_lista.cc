/*
  Scrivere un programma contenente la funzione di creazione di una
  lista semplice, la
  funzione di stampa di una lista e la funzione di eliminazione di una
  lista (implementata tramite la primitiva delete_elemElem). Il programma deve invocare le tre funzioni.
*/

#include <iostream>

using namespace std ;

struct elem
{
       int inf ;
       elem* pun ;
} ;

typedef elem* lista ;

/* Primitive */

int head(lista p){return p->inf;}

lista tail(lista p){return p->pun;}

lista insert_elem(lista l, elem* e){
	e->pun=l;
	return e;
}

lista delete_elem(lista l, elem* e){
	
		if (l==e)
			l=tail(l);
		else{
		elem* l1=l; 		
		while (tail(l1)!=e)
			l1=tail(l1);
		l1->pun=tail(e);}
		delete e;
		return l;
	
}

/* Funzioni */
void stampalista(lista p)
{
	while (p != NULL) {
		cout<<head(p)<<" " ; // stampa valore
		p = tail(p);     // spostamento sul
			                  // prossimo elemento
	}
	cout<<endl ;
}


lista crealista(int n)
{
      lista testa = NULL ;
      for (int i = 1 ; i <= n ; i++) {
          elem* p = new elem ;
          cout<<"Valore elemento "<<i<<": " ;
          cin>>p->inf ;
          testa=insert_elem(testa,p);
      }
      return testa ;
}


void eliminalista(lista &testa)
{
    /* .... */
}


int main()
{
    int n; 
    cout << "Inserire il numero di elementi da inserire nella lista" << endl;
    cin >> n; 
    lista testa = crealista(n) ;
    stampalista(testa) ;
    eliminalista(testa);
	cout << testa <<endl;

    return 0;
}
